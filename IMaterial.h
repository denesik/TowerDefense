#pragma once
#ifndef BaseMaterial_h__
#define BaseMaterial_h__

#include <memory>
#include "Shader.h"

class IMaterial;
typedef std::shared_ptr<IMaterial> PMaterial;

/// �������� ���������.
/// �������� ��������� ���������, ��������.
/// �������� ���� � ������� ���� ��������� � ��� ������������� ��.
class IMaterial
{
public:
  IMaterial(){};
  virtual ~IMaterial(){};

  /// ���������� ������� ��������.
  virtual void Use(PShader &shader) = 0;

};



#endif // BaseMaterial_h__
