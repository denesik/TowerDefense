#pragma once
#ifndef BaseShader_h__
#define BaseShader_h__

/// ������.
class BaseShader
{
public:
  BaseShader();
  virtual ~BaseShader();

  /// �������������� ������.
  virtual void Compile() = 0;

  /// ���������� ������.
  void Use();

protected:

  enum ShaderType
  {
    SHADER_VERTEX,
    SHADER_FRAGMENT,

    SHADER_TYPE_COUNT,
  };

  /// ������� ������.
  virtual unsigned int GetProgramId() = 0;

  /// ��������� ������.
  unsigned int CreateShader(char const *shader, ShaderType type);

  /// ������� ������
  void DeleteShader(unsigned int shaderId);

  /// ���������� ��� uniform �������� ���������� �������.
  void SetTextureUnit(const char *name, int location);

private:

  // ������������ ������� �������� ����� �������� �� ���������� �������� ����� ��������.
  static unsigned int ToShaderType(unsigned int shaderType);

};



#endif // BaseShader_h__
