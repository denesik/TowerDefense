#pragma once

#ifndef BaseModel_h__
#define BaseModel_h__

#include <memory>
#include "IMesh.h"
#include "IMaterial.h"
#include "Shader.h"

class IModel;
typedef std::shared_ptr<IModel> PModel;

/// �������� ����������� ������.
/// �������� ���, ��������, ������.
class IModel
{
public:
  IModel();
  virtual ~IModel();

  /// ������� �������� ������.
  virtual PMesh GetMesh() = 0;

  /// ������� �������� ������.
  virtual PMaterial GetMaterial() = 0;

  /// ������� �������� ������.
  virtual PShader GetShader() = 0;

};



#endif // BaseModel_h__
