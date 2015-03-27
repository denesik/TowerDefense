#pragma once

#ifndef Vertex_h__
#define Vertex_h__

#include <glm/glm.hpp>

/// �������� �������.
struct Vertex
{
  glm::vec3 point;    // �����
  glm::vec2 text;     // ���������� ����������
  glm::vec4 color;    // ����
};

#endif // Vertex_h__
