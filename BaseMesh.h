#pragma once

#ifndef BaseMesh_h__
#define BaseMesh_h__

#include <memory>
#include <vector>
#include "Vertex.h"

class BaseMesh;
typedef std::shared_ptr<BaseMesh> PMesh;

/// �������� ����.
/// �������� ������������� �����.
/// � ����������� � ����������� ������.
class BaseMesh
{
public:
  BaseMesh();
  virtual ~BaseMesh();

  /// ������� ����� ������.
  const std::vector<Vertex> &GetVertexBuffer() const;

  /// ������� ����� �������
  const std::vector<Vertex> &GetIndexBuffer() const;

  /// ���������� ����� ������.
  void SetVertexBuffer(const std::vector<Vertex> &vertexBuffer);

  /// ���������� ����� �������
  void SetIndexBuffer(const std::vector<Vertex> &indexBuffer);

  /// ������� ������ � ����� ������.
  void Compile();

  /// ���������� ��� �� ���������.
  void Bind();

protected:

  std::vector<Vertex> mVertexBuffer;
  std::vector<Vertex> mIndexBuffer;

  unsigned int	mVao;
  unsigned int	mVideoVertexBuffer;
  unsigned int	mVideoIndexBuffer;

};



#endif // BaseMesh_h__
