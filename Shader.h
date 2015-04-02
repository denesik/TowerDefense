#pragma once
#ifndef BaseShader_h__
#define BaseShader_h__

#include <memory>

class Shader;
typedef std::shared_ptr<Shader> PShader;

/// ������.
class Shader
{
public:
  Shader();
  ~Shader();

  /// �������������� ������.
  void Compile();

  /// ���������� ������.
  void Bind();

private:

  enum ShaderType
  {
    SHADER_VERTEX,
    SHADER_FRAGMENT,

    SHADER_TYPE_COUNT,
  };

  unsigned int mProgramId;

private:

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
