#include "BaseSprite.h"

#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

BaseSprite::BaseSprite(const glm::vec3 &pos, const glm::vec3 &rot)
  : mPos(pos), mRot(rot)
{

}

BaseSprite::~BaseSprite()
{
}

glm::mat4 BaseSprite::GetModelMat()
{
  glm::mat4 model(1.0f);
  model = glm::rotate(model, mRot.x, glm::vec3(1.0f, 0.0f, 0.0f));
  model = glm::rotate(model, mRot.y, glm::vec3(0.0f, 1.0f, 0.0f));
  model = glm::rotate(model, mRot.z, glm::vec3(0.0f, 0.0f, 1.0f));
  model = glm::translate(model, mPos);
  return model;
}


