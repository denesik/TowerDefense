#pragma once

#ifndef CameraPersp_h__
#define CameraPersp_h__

#include "ICamera.h"

class CameraPersp;
typedef std::shared_ptr<CameraPersp> PCameraPersp;

class CameraPersp : public ICamera
{
public:
  CameraPersp();
  ~CameraPersp();

  /// Получить матрицу вида.
  const glm::mat4 &GetView() override;

  /// Получить матрицу проекции.
  const glm::mat4 &GetProject() override;

  /// Угол обзора.
  void SetFov(float fov);

  /// Пропорции экрана.
  void SetAspect(float aspect);

  void SetFar(float far);

  void SetNear(float near);

  void RotateX(float angle);
  void RotateY(float angle);

  void MoveX(float dist);
  void MoveY(float dist);
  void MoveZ(float dist);

private:

  glm::mat4 mView;
  glm::mat4 mProjection;

  glm::mat4 mViewCurr;
  glm::mat4 mViewRotateY;

  float mFov;
  float mAspect;
  float mNear;
  float mFar;

private:

  void UpdateProjection();

};



#endif // CameraPersp_h__
