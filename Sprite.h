#pragma once

#ifndef Sprite_h__
#define Sprite_h__

#include <glm/glm.hpp>
#include <vector>

#include "Vertex.h"
#include "Texture.h"

class ISprite;
typedef std::shared_ptr<ISprite> PSprite;

/// ������. �������� ����������� �������.
class ISprite
{
public:
  ISprite(){};
  virtual ~ISprite(){};

  /// ������ �������.
  virtual const glm::uvec2 &GetSize() = 0;

  /// �������� ���������.
  virtual const std::vector<Vertex> &GetGeometry() = 0;

  /// �������� ��������.
  virtual PTexture GetTexture() = 0;

};

#endif // Sprite_h__
