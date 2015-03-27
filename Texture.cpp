#include "Texture.h"

Texture::Texture(const Bitmap &bitmap)
  : mSize(bitmap.GetSize())
{
  if(!mSize.x || !mSize.y || !IsPow2(mSize.x) || !IsPow2(mSize.y))
  {
    throw new TextureException(TextureException::INCORRECT_SIZE);
  }

}

Texture::~Texture()
{

}

