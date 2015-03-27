#include "SpriteQuad.h"


SpriteQuad::SpriteQuad(const glm::vec3 &pos, const glm::vec3 &rot, const glm::uvec2 size, PTexture texture)
  : BaseSprite(pos, rot), mSize(size), mTexture(texture)
{
  // Резервируем память под 6 точек.
  mData.reserve(6);
  mData.push_back({{0.0f, 0.0f, 0.0f},    {0.0f, 0.0f}, Color::black.Tof32Color()}); // lb
  mData.push_back({{size.x, size.y, 0.0f},{1.0f, 1.0f}, Color::black.Tof32Color()}); // rt
  mData.push_back({{0.0f, size.y, 0.0f},  {0.0f, 1.0f}, Color::black.Tof32Color()}); // lt
  mData.push_back({{size.x, size.y, 0.0f},{1.0f, 1.0f}, Color::black.Tof32Color()}); // rt
  mData.push_back({{0.0f, 0.0f, 0.0f},    {0.0f, 0.0f}, Color::black.Tof32Color()}); // lb
  mData.push_back({{size.x, 0.0f, 0.0f},  {1.0f, 0.0f}, Color::black.Tof32Color()}); // rb
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
