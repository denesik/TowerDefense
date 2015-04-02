#pragma once
#ifndef BaseShader_h__
#define BaseShader_h__

#include <memory>

class Shader;
typedef std::shared_ptr<Shader> PShader;

/// Шейдер.
class Shader
{
public:
  Shader();
  ~Shader();

  /// Скомпилировать шейдер.
  void Compile();

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
  unsigned int CreateShader(char const *shader, ShaderType type);

  /// Удалить шейдер
  void DeleteShader(unsigned int shaderId);

private:

  // Конвертирует внешнее описание типов шейдеров во внетреннее описание типов шейдеров.
  static unsigned int ToShaderType(unsigned int shaderType);

};



#endif // BaseShader_h__
