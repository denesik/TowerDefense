#ifndef BITMAP_H
#define BITMAP_H

#include <glm/glm.hpp>
#include <vector>
#include <string>

class BitmapException: public std::exception
{
public:
  BitmapException(unsigned int id)
    : mId(id)
  {
  }
  virtual const char* what() const throw()
  {
    return "Bitmap exception";
  }

  enum
  {
    FILE_NOT_FOUND,

    COUNT,
  };

private:
  const unsigned int mId;
};

/// Битовое изображение в оперативной памяти.
class Bitmap
{
public:
  /// Создает пустую битмапу.
  Bitmap();

  /// Загружает битмапу из png файла.
  Bitmap(const std::string &fileName);

  /// Разрушает битмапу.
  ~Bitmap();

  /// Вернуть размер битмапы.
  const glm::uvec2 &GetSize() const;

  /// Вернуть данные битмапы.
  const std::vector<unsigned char> &GetRaw() const;

private:

  std::vector<unsigned char> mData;

  // Размер битмапы.
  glm::uvec2 mSize;

};

#endif // BITMAP_H
