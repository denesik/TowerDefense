#include "BoxMesh.h"


BoxMesh::BoxMesh(unsigned char sideMask, const glm::vec3 &size)
  : mSideMask(sideMask), mSize(size)
{
}


BoxMesh::~BoxMesh()
{
}

const std::vector<Vertex> & BoxMesh::GetVertexBuffer()
{
  return mVertexBuffer;
}

const std::vector<Vertex> & BoxMesh::GetIndexBuffer()
{
  return mIndexBuffer;
}

void BoxMesh::Generate()
{

}
