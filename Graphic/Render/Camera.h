#pragma once

#ifndef Camera_h__
#define Camera_h__

#include "icamera.h"


class Camera : public ICamera
{
public:
  Camera();
  ~Camera();

  /// �������� ������� ����.
  const glm::mat4 &GetView() override;

  /// �������� ������� ��������.
  const glm::mat4 &GetProject() override;

  /// ���� ������.
  void SetFov(float fov);

  /// ��������� ������.
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



#endif // Camera_h__
