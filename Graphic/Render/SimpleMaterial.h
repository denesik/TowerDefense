#pragma once

#ifndef SimpleMaterial_h__
#define SimpleMaterial_h__

#include "IMaterial.h"
#include "Texture.h"


/// ������� ��������.
/// �������� ��������.
class SimpleMaterial : public IMaterial
{
public:
  SimpleMaterial();
  ~SimpleMaterial();

  void Use(const PShader &shader) override;

  void SetTexture(const PTexture &texture);

  const PTexture &GetTexture();

protected:

  PTexture mTexture;

};



#endif // SimpleMaterial_h__
