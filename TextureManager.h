#pragma once

#ifndef TextureManager_h__
#define TextureManager_h__

#include "Texture.h"
#include <string>
#include <unordered_map>



/// �������� �������.
/// ������ ��� ������� ��������.
class TextureManager
{
public:
  TextureManager(void);
  ~TextureManager(void);

  /// ��������� ��������� ��������.
  /// ���� �������� � ����� ������ ����������, ��� �� �����������.
  void LoadTexture(const std::string &fileName);

  /// �������� �������� �� �����.
  /// ���� �������� �� ����������, ������������ ������� ���������.
  PTexture GetTexture(const std::string &fileName) const;

private:

  std::unordered_map<std::string, PTexture> mTextures;

};



#endif // TextureManager_h__
