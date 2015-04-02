#pragma once

#ifndef BaseMesh_h__
#define BaseMesh_h__

#include <memory>
#include <vector>
#include "Vertex.h"

class BaseMesh;
typedef std::shared_ptr<BaseMesh> PMesh;

/// Описание меша.
/// Содержит полигональную сетку.
/// В оперативной и графической памяти.
class BaseMesh
{
public:
  BaseMesh();
  virtual ~BaseMesh();

  /// Вернуть буфер вершин.
  const std::vector<Vertex> &GetVertexBuffer() const;

  /// Вернуть буфер индесов
  const std::vector<Vertex> &GetIndexBuffer() const;

  /// Установить буфер вершин.
  void SetVertexBuffer(const std::vector<Vertex> &vertexBuffer);

  /// Установить буфер индесов
  void SetIndexBuffer(const std::vector<Vertex> &indexBuffer);

  /// Создать буферы в видео памяти.
  void Compile();

  /// Установить меш на отрисовку.
  void Bind();

protected:

  std::vector<Vertex> mVertexBuffer;
  std::vector<Vertex> mIndexBuffer;

  unsigned int	mVao;
  unsigned int	mVideoVertexBuffer;
  unsigned int	mVideoIndexBuffer;

};



#endif // BaseMesh_h__
