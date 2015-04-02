#include "BaseMesh.h"




BaseMesh::BaseMesh()
{

}

BaseMesh::~BaseMesh()
{

}

const std::vector<Vertex> & BaseMesh::GetVertexBuffer() const
{
  return mVertexBuffer;
}

const std::vector<Vertex> & BaseMesh::GetIndexBuffer() const
{
  return mIndexBuffer;
}

void BaseMesh::SetVertexBuffer(const std::vector<Vertex> &vertexBuffer)
{
  mVertexBuffer = vertexBuffer;
}

void BaseMesh::SetIndexBuffer(const std::vector<Vertex> &indexBuffer)
{
  mIndexBuffer = indexBuffer;
}

void BaseMesh::Compile()
{

}

void BaseMesh::Bind()
{

}
