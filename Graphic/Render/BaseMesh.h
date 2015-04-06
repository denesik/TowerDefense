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

  /// Создать буферы в видео памяти.
  void Create();

  /// Уничтожить буферы в видеопамяти.
  void Release();

  /// Установить меш на отрисовку.
  void Use();

protected:

  std::vector<Vertex> mVertexBuffer;
  std::vector<unsigned int> mIndexBuffer;

  unsigned int mVao;
  unsigned int mVideoVertexBuffer;
  unsigned int mVideoIndexBuffer;

};



#endif // BaseMesh_h__
