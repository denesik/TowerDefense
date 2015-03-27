#pragma once

#ifndef SpriteQuad_h__
#define SpriteQuad_h__

#include "BaseSprite.h"

class SpriteQuad : public BaseSprite
{
public:
  SpriteQuad(const glm::vec3 &pos, const glm::vec3 &rot, const glm::uvec2 size, PTexture texture);
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
