#pragma once

#ifndef Render_h__
#define Render_h__

#include "ICamera.h"
#include "Model.h"

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
  Render();
  ~Render();

  static void Initialize();

  /// Нарисовать модель в заданной позиции с заданным поворотом.
  void DrawModel(const PModel &model, const glm::vec3 &position, const glm::vec3 &rotation);

  /// Нарисовать все заданной камерой.
  void Draw(const PCamera &camera);

};



#endif // Render_h__
