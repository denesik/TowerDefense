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
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3(-(mSize.x / 2.0f), -(mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(0.0f, 0.0f)), sizeof(Vertex)); // lbb
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3(-(mSize.x / 2.0f), -(mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(1.0f, 0.0f)), sizeof(Vertex)); // lbf
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3(-(mSize.x / 2.0f),  (mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(1.0f, 1.0f)), sizeof(Vertex)); // ltf
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3(-(mSize.x / 2.0f),  (mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(0.0f, 1.0f)), sizeof(Vertex)); // ltb
    offsetVertex += sizeof(Vertex) * 4;
  }
  if(mSideMask & SIDE_RIGHT)
  {
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3( (mSize.x / 2.0f), -(mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(0.0f, 0.0f)), sizeof(Vertex)); // rbf
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3( (mSize.x / 2.0f), -(mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(1.0f, 0.0f)), sizeof(Vertex)); // rbb
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3( (mSize.x / 2.0f),  (mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(1.0f, 1.0f)), sizeof(Vertex)); // rtb
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3( (mSize.x / 2.0f),  (mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(0.0f, 1.0f)), sizeof(Vertex)); // rtf
    offsetVertex += sizeof(Vertex) * 4;
  }
  if(mSideMask & SIDE_TOP)
  {
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3(-(mSize.x / 2.0f),  (mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(0.0f, 0.0f)), sizeof(Vertex)); // ltf
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3( (mSize.x / 2.0f),  (mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(1.0f, 0.0f)), sizeof(Vertex)); // rtf
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3( (mSize.x / 2.0f),  (mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(1.0f, 1.0f)), sizeof(Vertex)); // rtb
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3(-(mSize.x / 2.0f),  (mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(0.0f, 1.0f)), sizeof(Vertex)); // ltb
    offsetVertex += sizeof(Vertex) * 4;
  }
  if(mSideMask & SIDE_BOTTOM)
  {
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3(-(mSize.x / 2.0f), -(mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(0.0f, 0.0f)), sizeof(Vertex)); // lbb
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3( (mSize.x / 2.0f), -(mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(1.0f, 0.0f)), sizeof(Vertex)); // rbb
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3( (mSize.x / 2.0f), -(mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(1.0f, 1.0f)), sizeof(Vertex)); // rbf
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3(-(mSize.x / 2.0f), -(mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(0.0f, 1.0f)), sizeof(Vertex)); // lbf
    offsetVertex += sizeof(Vertex) * 4;
  }
  if(mSideMask & SIDE_FRONT)
  {
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3(-(mSize.x / 2.0f), -(mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(0.0f, 0.0f)), sizeof(Vertex)); // lbf
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3( (mSize.x / 2.0f), -(mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(1.0f, 0.0f)), sizeof(Vertex)); // rbf
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3( (mSize.x / 2.0f),  (mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(1.0f, 1.0f)), sizeof(Vertex)); // rtf
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3(-(mSize.x / 2.0f),  (mSize.y / 2.0f),  (mSize.z / 2.0f)), glm::vec2(0.0f, 1.0f)), sizeof(Vertex)); // ltf
    offsetVertex += sizeof(Vertex) * 4;
  }
  if(mSideMask & SIDE_BACK)
  {
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3( (mSize.x / 2.0f), -(mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(0.0f, 0.0f)), sizeof(Vertex)); // rbb
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3(-(mSize.x / 2.0f), -(mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(1.0f, 0.0f)), sizeof(Vertex)); // lbb
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3(-(mSize.x / 2.0f),  (mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(1.0f, 1.0f)), sizeof(Vertex)); // ltb
    memcpy(&mVertexBuffer[offsetVertex], &Vertex(glm::vec3( (mSize.x / 2.0f),  (mSize.y / 2.0f), -(mSize.z / 2.0f)), glm::vec2(0.0f, 1.0f)), sizeof(Vertex)); // rtb
    offsetVertex += sizeof(Vertex) * 4;
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
      offsetVertex += sizeof(Vertex) * 4;
      offsetIndex += 6;
    }
  }
}

unsigned int BoxMesh::GetCountSides()
{
  return mSideMask & SIDE_LEFT + mSideMask & SIDE_RIGHT + mSideMask & SIDE_TOP + 
         mSideMask & SIDE_BOTTOM + mSideMask & SIDE_FRONT + mSideMask & SIDE_BACK;
}
