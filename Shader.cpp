#include "Shader.h"

#include <GL/glew.h>
#include <vector>
#include <assert.h>

unsigned int Shader::ToShaderType(unsigned int shaderType)
{
  assert(shaderType < SHADER_TYPE_COUNT);
  static unsigned int types[SHADER_TYPE_COUNT];
  types[SHADER_VERTEX] = GL_VERTEX_SHADER;
  types[SHADER_FRAGMENT] = GL_FRAGMENT_SHADER;
  return types[shaderType];
};


Shader::Shader()
{
}


Shader::~Shader()
{
}

void Shader::Bind()
{
  glUseProgram(mProgramId);
}

unsigned int Shader::CreateShader(char const *shader, ShaderType type)
{
  GLuint shaderId = glCreateShader(ShaderType(type));

  GLint isCompiled = GL_FALSE;
  int InfoLogLength;

  // Compile Vertex Shader
  //LOG(LOG_INFO, "Compiling shader: \"" + vertex_file_path + "\".");
  glShaderSource(shaderId, 1, &shader , NULL);
  glCompileShader(shaderId);

  // Check Vertex Shader
  glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isCompiled);

  if(!isCompiled)
  {
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> VertexShaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(shaderId, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
    //LOG(LOG_INFO, &VertexShaderErrorMessage[0]);
  }

  return shaderId;
}


void Shader::SetTextureUnit(const char *name, int location)
{
  GLint baseImageLoc = glGetUniformLocation(mProgramId, name);
  glUniform1i(baseImageLoc, location);
}

void Shader::DeleteShader(unsigned int shaderId)
{
  glDeleteShader(shaderId);
}

void Shader::Compile()
{

}
