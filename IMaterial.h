#pragma once
#ifndef BaseMaterial_h__
#define BaseMaterial_h__

#include <memory>
#include "Shader.h"

class IMaterial;
typedef std::shared_ptr<IMaterial> PMaterial;

/// ќписание материала.
/// —одержит параметры материала, текстуры.
/// ћатериал ищет в шейдере свои параметры и сам устанавливает их.
class IMaterial
{
public:
  IMaterial(){};
  virtual ~IMaterial(){};

  /// ”становить текущий материал.
  virtual void Bind(Shader &shader) = 0;

};



#endif // BaseMaterial_h__
