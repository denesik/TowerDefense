#pragma once

#ifndef BaseMesh_h__
#define BaseMesh_h__

#include <memory>
#include <vector>
#include "Vertex.h"

class IMesh;
typedef std::shared_ptr<IMesh> PMesh;

/// �������� ����.
/// �������� ������������� �����.
class IMesh
{
public:
  IMesh(void);
  virtual ~IMesh(void);

  /// ������� ����� ������.
  virtual const std::vector<Vertex> &GetVertexBuffer() = 0;

  /// ������� ����� �������
  virtual const std::vector<Vertex> &GetIndexBuffer() = 0;
};



#endif // BaseMesh_h__
