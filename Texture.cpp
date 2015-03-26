#include "Texture.h"

Texture::Texture()
{

}

Texture::Texture(const Bitmap &bitmap)
  : mSize(bitmap.GetSize())
{
  if(!IsPow2(mSize.x) || !IsPow2(mSize.y))
  {
    mSize = {0, 0};
    printf("Error. Texture size is not pow 2\n");
    return;
  }


}

Texture::~Texture()
{

}

