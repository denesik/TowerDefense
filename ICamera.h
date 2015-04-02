#pragma once

#ifndef ICamera_h__
#define ICamera_h__

#include <memory>
#include <glm/glm.hpp>

class ICamera;
typedef std::shared_ptr<ICamera> PCamera;

/// ������.
/// �������� ������� �������� � ����.
class ICamera
{
public:
  ICamera(){};
  virtual ~ICamera(){};

  /// �������� ������� ����.
  virtual const glm::mat4 &GetView() = 0;

  /// �������� ������� ��������.
  virtual const glm::mat4 &GetProject() = 0;
};



#endif // ICamera_h__
