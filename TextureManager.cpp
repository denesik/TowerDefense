#include "TextureManager.h"

#include "Bitmap.h"

TextureManager::TextureManager(void)
{
}


TextureManager::~TextureManager(void)
{
}

void TextureManager::LoadTexture(const std::string &fileName)
{
  if(mTextures.find(fileName) != mTextures.end())
  {
    printf("LoadTexture error\n");
    // �������� ��� ����������.
    return;
  }

  try
  {
    // ������ �������� � ��.
    Bitmap bitmap(fileName);
    mTextures[fileName] = PTexture(new Texture(bitmap));
  }
  catch(BitmapException *)
  {
    printf("LoadTexture error\n");
  	// ������ �������� ��������.
  }
  catch(TextureException *)
  {
    printf("LoadTexture error\n");
    // ������ �������� ��������.
  }
}

PTexture TextureManager::GetTexture(const std::string &fileName) const
{
  auto itTexture = mTextures.find(fileName);
  if(itTexture == mTextures.end())
  {
    // �������� �� �������.
    return nullptr;
  }

  return (*itTexture).second;
}
