#include "BaseMesh.h"

#include <GL/glew.h>


BaseMesh::BaseMesh()
{
  mVao = 0;
  mVideoVertexBuffer = 0;
  mVideoIndexBuffer = 0;
}

BaseMesh::~BaseMesh()
{
}

void BaseMesh::Create()
{
  // ������� vao.
  glGenVertexArrays(1, &mVao);

  // ���������� vao.
  glBindVertexArray(mVao);

  // ������� ��������� �����.
  glGenBuffers(1, &mVideoVertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, mVideoVertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(mVertexBuffer.back()) * mVertexBuffer.size(), &mVertexBuffer[0], GL_STATIC_DRAW);

  // �������� ������ ��������.
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glEnableVertexAttribArray(2);

  // ����������� ��������.
  GLchar* ptr = 0;
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(mVertexBuffer.back()), ptr + sizeof(float) * 0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(mVertexBuffer.back()), ptr + sizeof(float) * 3);
  glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(mVertexBuffer.back()), ptr + sizeof(float) * 5);

  // ������� ��������� �����.
  glGenBuffers(1, &mVideoIndexBuffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mVideoIndexBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mIndexBuffer.back()) * mIndexBuffer.size(), &mIndexBuffer[0], GL_STATIC_DRAW);

  glBindVertexArray(0);
}


void BaseMesh::Release()
{
  glBindVertexArray(mVao);

  // ��������� ��������.
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glDisableVertexAttribArray(2);

  // ���������� ������.
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  // ��������� vao.
  glBindVertexArray(0);

  // ������� vao.
  glDeleteVertexArrays(1, &mVao);

  // ������� ������.
  glDeleteBuffers(1, &mVideoVertexBuffer);
  glDeleteBuffers(1, &mVideoIndexBuffer);
}


void BaseMesh::Use()
{
  glBindVertexArray(mVao);

  glDrawElements(GL_TRIANGLES, mVideoIndexBuffer, GL_UNSIGNED_INT, NULL);

  glBindVertexArray(0);
}

