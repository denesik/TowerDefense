#include "CameraPersp.h"

#include <glm/gtc/matrix_transform.hpp>


CameraPersp::CameraPersp(void)
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
  mFar = -100.0f;
}


CameraPersp::~CameraPersp(void)
{
}

const glm::mat4 &CameraPersp::GetView()
{
  mView = mViewRotateY * mViewCurr;
  return mView;
}

const glm::mat4 &CameraPersp::GetProject()
{
  return mProjection;
}

void CameraPersp::SetFov(float fov)
{
  mFov = fov;
}

void CameraPersp::SetAspect(float aspect)
{
  mAspect = aspect;
}

void CameraPersp::SetFar(float far)
{
  mFar = far;
}

void CameraPersp::SetNear(float near)
{
  mNear = near;
}

void CameraPersp::UpdateProjection()
{
  mProjection = glm::perspective(mFov, mAspect, mNear, mFar);
}

void CameraPersp::RotateX(float angle)
{
  mViewCurr = glm::rotate(mViewCurr, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
}

void CameraPersp::RotateY(float angle)
{
  mViewRotateY = glm::rotate(mViewRotateY, glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.0f));
}

void CameraPersp::MoveX(float dist)
{
  mViewCurr = glm::translate(mViewCurr, glm::vec3(-dist, 0.0f, 0.0f));
}

void CameraPersp::MoveY(float dist)
{
  mViewCurr = glm::translate(mViewCurr, glm::vec3(0.0f, -dist, 0.0f));
}

void CameraPersp::MoveZ(float dist)
{
  mViewCurr = glm::translate(mViewCurr, glm::vec3(0.0f, 0.0f, -dist));
}
