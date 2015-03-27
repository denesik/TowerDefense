#pragma once

#ifndef Sprite_h__
#define Sprite_h__

#include <glm/glm.hpp>
#include <vector>

#include "Vertex.h"
#include "Texture.h"

class ISprite;
typedef std::shared_ptr<ISprite> PSprite;

/// Спрайт. Рисуется графическим движком.
class ISprite
{
public:
  ISprite(){};
  virtual ~ISprite(){};

  /// Размер спрайта.
  virtual const glm::uvec2 &GetSize() = 0;

  /// Получить геометрию.
  virtual const std::vector<Vertex> &GetGeometry() = 0;

  /// Получить текстуру.
  virtual PTexture GetTexture() = 0;

};

#endif // Sprite_h__
