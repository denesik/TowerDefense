#pragma once

#ifndef BaseModel_h__
#define BaseModel_h__

#include <memory>
#include "IMesh.h"
#include "IMaterial.h"
#include "Shader.h"

class IModel;
typedef std::shared_ptr<IModel> PModel;

/// Описание графической модели.
/// Содержит меш, материал, шейдер.
class IModel
{
public:
  IModel();
  virtual ~IModel();

  /// Вернуть материал модели.
  virtual PMesh GetMesh() = 0;

  /// Вернуть материал модели.
  virtual PMaterial GetMaterial() = 0;

  /// Вернуть материал модели.
  virtual PShader GetShader() = 0;

};



#endif // BaseModel_h__
