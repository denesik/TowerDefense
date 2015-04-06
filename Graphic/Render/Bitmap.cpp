#include "Bitmap.h"

#include "lodepng/lodepng.h"

Bitmap::Bitmap()
{
}

Bitmap::Bitmap(const std::string &fileName)
{
  unsigned error = lodepng::decode(mData, mSize.x, mSize.y, fileName);

  if(error)
  {
    throw new BitmapException(BitmapException::FILE_NOT_FOUND);
  }
}

Bitmap::Bitmap(const glm::uvec2 &size, const Color &color)
  : mSize(size)
{
  mData.resize(mSize.x * mSize.y * sizeof(color));
  for(unsigned int i = 0; i < mData.size(); i += sizeof(color))
  {
    memcpy(&mData[i], &color, sizeof(color));
  }
}

Bitmap::~Bitmap()
{
}

const glm::uvec2 &Bitmap::GetSize() const
{
  return mSize;
}

const std::vector<unsigned char> &Bitmap::GetRaw() const
{
  return mData;
}
