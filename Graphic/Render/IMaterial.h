#pragma once
#ifndef BaseMaterial_h__
#define BaseMaterial_h__

#include <memory>
#include "Shader.h"

class IMaterial;
typedef std::shared_ptr<IMaterial> PMaterial;

/// Описание материала.
/// Содержит параметры материала, текстуры.
/// Материал ищет в шейдере свои параметры и сам устанавливает их.
class IMaterial
{
public:
  IMaterial(){};
  virtual ~IMaterial(){};

  /// Установить текущий материал.
  virtual void Use(const PShader &shader) = 0;

};



#endif // BaseMaterial_h__
