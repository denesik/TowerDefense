#include "BoxMesh.h"


BoxMesh::BoxMesh(unsigned char sideMask, const glm::vec3 &size)
  : mSideMask(sideMask), mSize(size)
{
  assert(mSideMask <= SIDE_ALL);

}


BoxMesh::~BoxMesh()
{
}

void BoxMesh::Generate()
{
  unsigned int sideCount = GetCountSides();
  mVertexBuffer.resize(sideCount * 4);

  unsigned int offsetVertex = 0;
  if(mSideMask & SIDE_LEFT)
  {
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3(-(mSize.x / 2.0f), -(mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(0.0f, 0.0f)); // lbb
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3(-(mSize.x / 2.0f), -(mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(1.0f, 0.0f)); // lbf
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3(-(mSize.x / 2.0f),  (mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(1.0f, 1.0f)); // ltf
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3(-(mSize.x / 2.0f),  (mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(0.0f, 1.0f)); // ltb
    offsetVertex += 4;
  }
  if(mSideMask & SIDE_RIGHT)
  {
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3( (mSize.x / 2.0f), -(mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(0.0f, 0.0f)); // rbf
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3( (mSize.x / 2.0f), -(mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(1.0f, 0.0f)); // rbb
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3( (mSize.x / 2.0f),  (mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(1.0f, 1.0f)); // rtb
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3( (mSize.x / 2.0f),  (mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(0.0f, 1.0f)); // rtf
    offsetVertex += 4;
  }
  if(mSideMask & SIDE_TOP)
  {
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3(-(mSize.x / 2.0f),  (mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(0.0f, 0.0f)); // ltf
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3( (mSize.x / 2.0f),  (mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(1.0f, 0.0f)); // rtf
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3( (mSize.x / 2.0f),  (mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(1.0f, 1.0f)); // rtb
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3(-(mSize.x / 2.0f),  (mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(0.0f, 1.0f)); // ltb
    offsetVertex += 4;
  }
  if(mSideMask & SIDE_BOTTOM)
  {
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3(-(mSize.x / 2.0f), -(mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(0.0f, 0.0f)); // lbb
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3( (mSize.x / 2.0f), -(mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(1.0f, 0.0f)); // rbb
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3( (mSize.x / 2.0f), -(mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(1.0f, 1.0f)); // rbf
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3(-(mSize.x / 2.0f), -(mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(0.0f, 1.0f)); // lbf
    offsetVertex += 4;
  }
  if(mSideMask & SIDE_FRONT)
  {
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3(-(mSize.x / 2.0f), -(mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(0.0f, 0.0f)); // lbf
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3( (mSize.x / 2.0f), -(mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(1.0f, 0.0f)); // rbf
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3( (mSize.x / 2.0f),  (mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(1.0f, 1.0f)); // rtf
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3(-(mSize.x / 2.0f),  (mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(0.0f, 1.0f)); // ltf
    offsetVertex += 4;
  }
  if(mSideMask & SIDE_BACK)
  {
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3( (mSize.x / 2.0f), -(mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(0.0f, 0.0f)); // rbb
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3(-(mSize.x / 2.0f), -(mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(1.0f, 0.0f)); // lbb
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3(-(mSize.x / 2.0f),  (mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(1.0f, 1.0f)); // ltb
    mVertexBuffer[offsetVertex] = Vertex(glm::vec3( (mSize.x / 2.0f),  (mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(0.0f, 1.0f)); // rtb
    offsetVertex += 4;
  }

  offsetVertex = 0;
  unsigned int offsetIndex = 0;
  mIndexBuffer.resize(sideCount * 6);
  for(unsigned int i = 0; i < 6; ++i)
  {
    if(mSideMask & (1 << i))
    {
      mIndexBuffer[offsetIndex + 0] = offsetVertex + 0; // lb
      mIndexBuffer[offsetIndex + 1] = offsetVertex + 2; // rt
      mIndexBuffer[offsetIndex + 2] = offsetVertex + 3; // lt
      mIndexBuffer[offsetIndex + 3] = offsetVertex + 0; // lb
      mIndexBuffer[offsetIndex + 4] = offsetVertex + 1; // rb
      mIndexBuffer[offsetIndex + 5] = offsetVertex + 2; // rt
      offsetVertex += 4;
      offsetIndex += 6;
    }
  }
}

unsigned int BoxMesh::GetCountSides()
{
  return ((mSideMask & SIDE_LEFT) >> 0) + ((mSideMask & SIDE_RIGHT) >> 1) + ((mSideMask & SIDE_TOP) >> 2) + 
         ((mSideMask & SIDE_BOTTOM) >> 3) + ((mSideMask & SIDE_FRONT) >> 4) + ((mSideMask & SIDE_BACK) >> 5);
}
