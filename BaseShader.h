#pragma once
#ifndef BaseShader_h__
#define BaseShader_h__

/// Шейдер.
class BaseShader
{
public:
  BaseShader();
  virtual ~BaseShader();

  /// Скомпилировать шейдер.
  virtual void Compile() = 0;

  /// Установить шейдер.
  void Use();

protected:

  enum ShaderType
  {
    SHADER_VERTEX,
    SHADER_FRAGMENT,

    SHADER_TYPE_COUNT,
  };

  /// Вернуть шейдер.
  virtual unsigned int GetProgramId() = 0;

  /// Загрузить шейдер.
  unsigned int CreateShader(char const *shader, ShaderType type);

  /// Удалить шейдер
  void DeleteShader(unsigned int shaderId);

  /// Установить для uniform текстуры текстурную локацию.
  void SetTextureUnit(const char *name, int location);

private:

  // Конвертирует внешнее описание типов шейдеров во внетреннее описание типов шейдеров.
  static unsigned int ToShaderType(unsigned int shaderType);

};



#endif // BaseShader_h__
