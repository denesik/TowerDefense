#pragma once

#ifndef ICamera_h__
#define ICamera_h__

#include <memory>
#include <glm/glm.hpp>

class ICamera;
typedef std::shared_ptr<ICamera> PCamera;

/// Камера.
/// Содержит матрицы проекции и вида.
class ICamera
{
public:
  ICamera(){};
  virtual ~ICamera(){};

  /// Получить матрицу вида.
  virtual const glm::mat4 &GetView() = 0;

  /// Получить матрицу проекции.
  virtual const glm::mat4 &GetProject() = 0;
};



#endif // ICamera_h__
