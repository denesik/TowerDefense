#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>


Camera::Camera(void)
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
//   mView = glm::lookAt
//     (
//       glm::vec3(0,0,1), // eye
//       glm::vec3(0,0,0), // center
//       glm::vec3(0,1,0)  // up
//     );
}
