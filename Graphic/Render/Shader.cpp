#include "Shader.h"

#include <GL/glew.h>
#include <vector>
#include <assert.h>
#include <fstream>

unsigned int Shader::ToShaderType(unsigned int shaderType)
{
  assert(shaderType < SHADER_TYPE_COUNT);
  static unsigned int types[SHADER_TYPE_COUNT];
  types[SHADER_VERTEX] = GL_VERTEX_SHADER;
  types[SHADER_FRAGMENT] = GL_FRAGMENT_SHADER;
  return types[shaderType];
};


Shader::Shader(const std::string &shaderName)
{
  // Читаем и создаем шейдеры.
  // Если файл не существует, шейдер не создается.
  std::vector<int> shaders(SHADER_TYPE_COUNT, 0);

  try
  {
    shaders[SHADER_VERTEX] = CreateShader(ReadTxtFile(shaderName + ".vs"), SHADER_VERTEX);
    shaders[SHADER_FRAGMENT] = CreateShader(ReadTxtFile(shaderName + ".fs"), SHADER_FRAGMENT);
  }
  catch (ShaderException *)
  {
    // Удалим все созданные шейдеры.
    for(auto it = shaders.begin(); it != shaders.end(); ++it)
    {
      DeleteShader(*it);
    }
    throw;
  }

  // Очищаем стек ошибок ogl.
  while(!glGetError()){};

  // Пытаемся собрать программу из всех прочитанных шейдеров.
  mProgramId = glCreateProgram();
  for(auto it = shaders.begin(); it != shaders.end(); ++it)
  {
    if(*it)
    {
      glAttachShader(mProgramId, *it);
    }
  }
  glLinkProgram(mProgramId);

  // Удаляем шейдеры.
  for(auto it = shaders.begin(); it != shaders.end(); ++it)
  {
    DeleteShader(*it);
  }

  // Проверяем статус линковки
  GLint link = GL_FALSE;
  glGetProgramiv(mProgramId, GL_LINK_STATUS, &link);
  if(link != GL_TRUE || glGetError())
  {
    GLint linkerLogSize = 0;
    glGetProgramiv(mProgramId, GL_INFO_LOG_LENGTH, &linkerLogSize);
    if(linkerLogSize)
    {
      std::string linkerLog(linkerLogSize, '\0');
      glGetProgramInfoLog(mProgramId, linkerLogSize, NULL, &linkerLog[0]);
    }

    glDeleteProgram(mProgramId);
    throw new ShaderException(ShaderException::SHADER_NOT_CREATED);
  }
}


Shader::~Shader()
{
  glDeleteProgram(mProgramId);
}

void Shader::Use()
{
  glUseProgram(mProgramId);
}

unsigned int Shader::CreateShader(const std::string &data, ShaderType type)
{
  if(data.empty())
  {
    return 0;
  }

  // Очищаем стек ошибок ogl.
  while(!glGetError()){};

  GLuint shader = glCreateShader(ShaderType(type));

  if(glGetError())
  {
    throw new ShaderException(ShaderException::SHADER_NOT_CREATED);
  }

  char const *sourcePointer = data.c_str();
  glShaderSource(shader, 1, &sourcePointer, NULL);
  glCompileShader(shader);

  GLint compiled = GL_FALSE;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

  if(compiled != GL_TRUE || glGetError())
  {
    int infoLogLength = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
    if(infoLogLength)
    {
      std::vector<char> VertexShaderErrorMessage(infoLogLength);
      glGetShaderInfoLog(shader, infoLogLength, NULL, &VertexShaderErrorMessage[0]);
    }

    glDeleteShader(shader);
    throw new ShaderException(ShaderException::SHADER_NOT_CREATED);
  }

  return shader;
}

void Shader::DeleteShader(unsigned int shader)
{
  glDeleteShader(shader);
}

unsigned int Shader::GetUniformLocation(const char *name)
{
  return glGetUniformLocation(mProgramId, name);
}

std::string Shader::ReadTxtFile(const std::string &fileName)
{
  std::string code;
  std::ifstream file(fileName, std::ios::in);
  if(file.is_open())
  {
    std::string line = "";
    while(getline(file, line))
      code += "\n" + line;
    file.close();
  }

  return code;
}
