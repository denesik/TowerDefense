#pragma once

#ifndef SpriteQuad_h__
#define SpriteQuad_h__

#include "Sprite.h"

class SpriteQuad : public ISprite
{
public:
  SpriteQuad(PTexture texture);
  ~SpriteQuad();

  /// Размер спрайта.
  const glm::uvec2 &GetSize();

  /// Получить геометрию.
  const std::vector<Vertex> &GetGeometry();

  /// Получить текстуру.
  PTexture GetTexture();

private:

  glm::uvec2 mSize;
  std::vector<Vertex> mData;
  PTexture mTexture;
};



#endif // SpriteQuad_h__
