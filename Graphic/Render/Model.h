#pragma once

#ifndef BaseModel_h__
#define BaseModel_h__

#include <memory>
#include "BaseMesh.h"
#include "IMaterial.h"
#include "Shader.h"

class Model;
typedef std::shared_ptr<Model> PModel;

/// �������� ����������� ������.
/// �������� ���, ��������, ������.
class Model
{
public:
  Model();
  virtual ~Model();

  /// ������� ���.
  const PMesh &GetMesh();

  /// ���������� ���.
  void SetMesh(const PMesh &mesh);

  /// ������� ��������.
  const PMaterial &GetMaterial();

  /// ���������� ��������.
  void SetMaterial(const PMaterial &material);

  /// ������� ������.
  const PShader &GetShader();

  /// ���������� ������.
  void SetShader(const PShader &shader);

private:

  PMesh mMesh;
  PMaterial mMaterial;
  PShader mShader;

};


#endif // BaseModel_h__
