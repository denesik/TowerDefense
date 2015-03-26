#ifndef TEXTURE_H
#define TEXTURE_H

#include <glm/glm.hpp>
#include "Bitmap.h"

/// Текстура. Находится в видеопамяти.
class Texture
{
public:
  /// Создать пустую текстуру.
  /// Текстура не создается в видеопамяти.
  Texture();

  /// Создать текстуру на основе битмапы.
  Texture(const Bitmap &bitmap);

  /// Разрушить текстуру.
  ~Texture();

private:
  // id текстуры. 0 - не существующая текстура.
  unsigned int mId;

  // Размер текстуры в текстелях.
  glm::uvec2 mSize;

private:

  // Вспомогательная функция. Узнает, является ли число степенью 2.
  bool IsPow2(unsigned int a)
  {
    return !(a & (a - 1));
  }

};


#endif // TEXTURE_H
