#pragma once

#ifndef SpriteQuad_h__
#define SpriteQuad_h__

#include "sprite.h"

class SpriteQuad : public ISprite
{
public:
  SpriteQuad(PTexture texture);
  ~SpriteQuad();

  /// ������ �������.
  const glm::uvec2 &GetSize();

  /// �������� ���������.
  const std::vector<Vertex> &GetGeometry();

  /// �������� ��������.
  PTexture GetTexture();

private:

  glm::uvec2 mSize;
  std::vector<Vertex> mData;
  PTexture mTexture;
};



#endif // SpriteQuad_h__
