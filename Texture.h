#ifndef TEXTURE_H
#define TEXTURE_H

#include <glm/glm.hpp>
#include "Bitmap.h"

class TextureException: public std::exception
{
public:
  TextureException(unsigned int id)
    : mId(id)
  {
  }
  virtual const char *what() const throw()
  {
    return "Texture exception";
  }

  enum
  {
    INCORRECT_SIZE,

    COUNT,
  };

private:
  const unsigned int mId;
};


/// Текстура. Находится в видеопамяти.
class Texture
{
public:
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
