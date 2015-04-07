#pragma once

#ifndef BoxMesh_h__
#define BoxMesh_h__

#include <glm/glm.hpp>
#include "BaseMesh.h"

class BoxMesh;
typedef std::shared_ptr<BoxMesh> PBoxMesh;

/// Меш.
/// Создает параллепипед указанного размера из указанных сторон.
class BoxMesh : public BaseMesh
{
public:
  BoxMesh(unsigned char sideMask = SIDE_ALL, const glm::vec3 &size = glm::vec3(1.0f, 1.0f, 1.0f));
  ~BoxMesh();

  /// Сгенерировать меш по заданным параметрам.
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

  glm::vec3 mSize;
  unsigned char mSideMask;

private:

  unsigned int GetCountSides();

};



#endif // BoxMesh_h__
