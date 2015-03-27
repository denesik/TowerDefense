#include "SpriteQuad.h"


SpriteQuad::SpriteQuad(PTexture texture)
  : mSize(texture->GetSize()), mTexture(texture)
{

}


SpriteQuad::~SpriteQuad(void)
{
}

const glm::uvec2 & SpriteQuad::GetSize()
{
  return mSize;
}

const std::vector<Vertex> & SpriteQuad::GetGeometry()
{
  return mData;
}

PTexture SpriteQuad::GetTexture()
{
  return mTexture;
}
