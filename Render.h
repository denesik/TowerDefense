#pragma once

#ifndef Render_h__
#define Render_h__

#include "BaseSprite.h"
#include "Texture.h"


class RenderException: public std::exception
{
public:
  RenderException(unsigned int id)
    : mId(id)
  {
  }
  virtual const char *what() const throw()
  {
    return "Render exception";
  }

  enum
  {
    RENDER_NOT_INITIALIZED,

    COUNT,
  };

private:
  const unsigned int mId;
};



class Render
{
public:
  Render(void);
  ~Render(void);

  static void Initialize();

  /// Нарисовать все.
  void Draw();

  /// Нарисовать спрайт.
  void DrawSprite(PBaseSprite sprite);
};



#endif // Render_h__
