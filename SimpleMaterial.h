#pragma once

#ifndef SimpleMaterial_h__
#define SimpleMaterial_h__

#include "IMaterial.h"


/// Шаблон простого материала.
/// Использует одну текстуру на нулевом слоте.
class SimpleMaterial : public IMaterial
{
public:
  SimpleMaterial();
  ~SimpleMaterial();



};



#endif // SimpleMaterial_h__
