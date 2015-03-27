#include "Texture.h"

#include "RenderErrorChecker.h"
#include <GL/glew.h>


Texture::Texture(const Bitmap &bitmap)
  : mSize(bitmap.GetSize()), mTextureId(0)
{
  if(!mSize.x || !mSize.y || !IsPow2(mSize.x) || !IsPow2(mSize.y))
  {
    throw new TextureException(TextureException::INCORRECT_SIZE);
  }

  bool smoothing = false; 
  bool mipmap = false;

  glGenTextures(1, &mTextureId);
//   if(!mTextureId)
//   {
//     throw new TextureException(TextureException::TEXTURE_NOT_CREATED);
//   }

  glBindTexture(GL_TEXTURE_2D, mTextureId);
  
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, smoothing ? GL_LINEAR : GL_NEAREST);

  if(mipmap)
  {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, smoothing ? GL_LINEAR_MIPMAP_LINEAR : GL_NEAREST_MIPMAP_NEAREST);
  }
  else
  {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, smoothing ? GL_LINEAR : GL_NEAREST);
  }

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mSize.x, mSize.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, &bitmap.GetRaw()[0]);
  RenderCheckErrors();

  if(mipmap)
  {
    glGenerateMipmap(GL_TEXTURE_2D);
    RenderCheckErrors();
  }
  
}

Texture::~Texture()
{
  glDeleteTextures(1, &mTextureId);
  RenderCheckErrors();
}

const glm::uvec2 & Texture::GetSize()
{
  return mSize;
}

