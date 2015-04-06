#include "BaseMesh.h"

#include <GL/glew.h>


BaseMesh::BaseMesh()
{
  mVao = 0;
  glGenVertexArrays(1, &mVao);
  mVideoVertexBuffer = 0;
  mVideoIndexBuffer = 0;
}

BaseMesh::~BaseMesh()
{
  glDeleteVertexArrays (1, &mVao);
}

void BaseMesh::Create()
{
  glBindVertexArray(mVao);

  glGenBuffers(1, &mVideoVertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, mVideoVertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(mVertexBuffer[0]) * mVertexBuffer.size(), &mVertexBuffer[0], GL_STATIC_DRAW);

  glGenBuffers(1, &mVideoIndexBuffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mVideoIndexBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mIndexBuffer[0]) * mIndexBuffer.size(), &mIndexBuffer[0], GL_STATIC_DRAW);

  glBindVertexArray(0);
}


void BaseMesh::Release()
{
  glBindVertexArray(mVao);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  glBindVertexArray(0);

  glDeleteBuffers(1, &mVideoVertexBuffer);
  glDeleteBuffers(1, &mVideoIndexBuffer);
}


void BaseMesh::Use()
{
  glBindVertexArray(mVao);

  glDrawElements(GL_TRIANGLES, mVideoIndexBuffer, GL_UNSIGNED_INT, NULL);

  glBindVertexArray(0);
}

