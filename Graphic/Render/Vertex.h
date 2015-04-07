#pragma once

#ifndef Vertex_h__
#define Vertex_h__

#include <glm/glm.hpp>

/// Описание вершины.
struct Vertex
{
  Vertex();

  Vertex(const glm::vec3 &p, const glm::vec2 &t = glm::vec2(), const glm::vec4 &c = glm::vec4());

  glm::vec3 position;     // Точка
  glm::vec2 texcoord;     // Текстурные координаты
  glm::vec4 color;        // Цвет
};

#endif // Vertex_h__
