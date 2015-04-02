#pragma once

#ifndef BoxMesh_h__
#define BoxMesh_h__

#include <glm/glm.hpp>
#include "IMesh.h"


/// ���.
class BoxMesh : public IMesh
{
public:
  BoxMesh(unsigned char sideMask = SIDE_ALL, const glm::vec3 &size = glm::vec3(1.0f, 1.0f, 1.0f));
  ~BoxMesh();

  /// ������� ����� ������.
  const std::vector<Vertex> &GetVertexBuffer() override;

  /// ������� ����� �������
  const std::vector<Vertex> &GetIndexBuffer() override;

  /// ������������� ��� �� �������� ����������.
  void Generate();

public:

  enum
  {
    SIDE_LEFT = 0x01,
    SIDE_RIGHT = 0x02,
    SIDE_TOP = 0x04,
    SIDE_BOTTOM = 0x08,
    SIDE_FRONT = 0x10,
    SIDE_BACK = 0x20,

    SIDE_ALL = 0x3F,
  };

private:

  std::vector<Vertex> mVertexBuffer;
  std::vector<Vertex> mIndexBuffer;

  glm::vec3 mSize;
  unsigned char mSideMask;
};



#endif // BoxMesh_h__
