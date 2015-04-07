#pragma once

#ifndef BaseModel_h__
#define BaseModel_h__

#include <memory>
#include "BaseMesh.h"
#include "IMaterial.h"
#include "Shader.h"

class Model;
typedef std::shared_ptr<Model> PModel;

/// Описание графической модели.
/// Содержит меш, материал, шейдер.
class Model
{
public:
  Model();
  virtual ~Model();

  /// Вернуть меш.
  const PMesh &GetMesh();

  /// Установить меш.
  void SetMesh(const PMesh &mesh);

  /// Вернуть материал.
  const PMaterial &GetMaterial();

  /// Установить материал.
  void SetMaterial(const PMaterial &material);

  /// Вернуть шейдер.
  const PShader &GetShader();

  /// Установить шейдер.
  void SetShader(const PShader &shader);

private:

  PMesh mMesh;
  PMaterial mMaterial;
  PShader mShader;

};


#endif // BaseModel_h__
