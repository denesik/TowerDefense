#pragma once

#ifndef BaseSprite_h__
#define BaseSprite_h__

#include <glm/glm.hpp>
#include <vector>

#include "Vertex.h"
#include "Texture.h"

class BaseSprite;
typedef std::shared_ptr<BaseSprite> PBaseSprite;

/// Спрайт. Рисуется графическим движком.
class BaseSprite
{
public:
  BaseSprite(const glm::vec3 &pos = glm::vec3(), const glm::vec3 &rot = glm::vec3());
  virtual ~BaseSprite();

  /// Размер спрайта.
  virtual const glm::uvec2 &GetSize() = 0;

  /// Получить геометрию.
  virtual const std::vector<Vertex> &GetGeometry() = 0;

  /// Получить текстуру.
  virtual PTexture GetTexture() = 0;

  /// Получить матрицу модели.
  virtual glm::mat4 GetModelMat();

protected:

  glm::vec3 mPos;
  glm::vec3 mRot;

};

#endif // BaseSprite_h__
