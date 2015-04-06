#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>


Camera::Camera(void)
  : mViewCurr(glm::lookAt
              (
                glm::vec3(0,0,1), // eye
                glm::vec3(0,0,0), // center
                glm::vec3(0,1,0)  // up
              )), mViewRotateY(1.0f)
{
  mFov = 45.0f;
  mAspect = 1.0f;
  mNear = 0.0f;
  mFar = 1.0f;
}


Camera::~Camera(void)
{
}

const glm::mat4 &Camera::GetView()
{
  mView = mViewRotateY * mViewCurr;
  return mView;
}

const glm::mat4 &Camera::GetProject()
{
  return mProjection;
}

void Camera::SetFov(float fov)
{
  mFov = fov;
}

void Camera::SetAspect(float aspect)
{
  mAspect = aspect;
}

void Camera::SetFar(float far)
{
  mFar = far;
}

void Camera::SetNear(float near)
{
  mNear = near;
}

void Camera::UpdateProjection()
{
  mProjection = glm::perspective(mFov, mAspect, mNear, mFar);
}

void Camera::RotateX(float angle)
{
  mViewCurr = glm::rotate(mViewCurr, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::RotateY(float angle)
{
  mViewRotateY = glm::rotate(mViewRotateY, glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.0f));
}

void Camera::MoveX(float dist)
{
  mViewCurr = glm::translate(mViewCurr, glm::vec3(-dist, 0.0f, 0.0f));
}

void Camera::MoveY(float dist)
{
  mViewCurr = glm::translate(mViewCurr, glm::vec3(0.0f, -dist, 0.0f));
}

void Camera::MoveZ(float dist)
{
  mViewCurr = glm::translate(mViewCurr, glm::vec3(0.0f, 0.0f, -dist));
}
