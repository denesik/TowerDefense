#include "Bitmap.h"

#include <lodepng/lodepng.h>

Bitmap::Bitmap()
{
}

Bitmap::Bitmap(const std::string &fileName)
{
  unsigned error = lodepng::decode(mData, mSize.x, mSize.y, fileName);

  //if there's an error, display it
  if(error)
  {
    printf("Lodepng load error: %s\n", lodepng_error_text(error));
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
