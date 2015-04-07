#pragma once
#ifndef BaseShader_h__
#define BaseShader_h__

#include <memory>
#include <string>

class ShaderException: public std::exception
{
public:
  ShaderException(unsigned int id)
    : mId(id)
  {
  }
  virtual const char *what() const throw()
  {
    return "Shader exception";
  }

  enum
  {
    SHADER_NOT_CREATED,
    COUNT,
  };

private:
  const unsigned int mId;
};


class Shader;
typedef std::shared_ptr<Shader> PShader;

/// Шейдер.
class Shader
{
public:
  Shader(const std::string &shaderName);
  ~Shader();

  /// Установить шейдер.
  void Use();

  /// Вернуть идентификатор параметра шейдера.
  unsigned int GetUniformLocation(const char *name);

private:

  enum ShaderType
  {
    SHADER_VERTEX,
    SHADER_FRAGMENT,

    SHADER_TYPE_COUNT,
  };

  unsigned int mProgramId;

private:

  /// Загрузить шейдер.
  unsigned int CreateShader(const std::string &data, ShaderType type);

  /// Удалить шейдер
  void DeleteShader(unsigned int shaderId);

  /// Прочитать файл.
  std::string ReadTxtFile(const std::string &fileName);

private:

  // Конвертирует внешнее описание типов шейдеров во внетреннее описание типов шейдеров.
  static unsigned int ToShaderType(unsigned int shaderType);

};



#endif // BaseShader_h__
