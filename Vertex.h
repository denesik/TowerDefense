#pragma once

#ifndef Vertex_h__
#define Vertex_h__

#include <glm/glm.hpp>

/// Описание вершины.
struct Vertex
{
  glm::vec3 point;    // Точка
  glm::vec2 text;     // Текстурные координаты
  glm::vec4 color;    // Цвет
};

#endif // Vertex_h__
