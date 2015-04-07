#include "SimpleMaterial.h"

#include "RenderErrorChecker.h"
#include <GL/glew.h>
#define make_str(val) #val

SimpleMaterial::SimpleMaterial(void)
{
}


SimpleMaterial::~SimpleMaterial(void)
{
}

void SimpleMaterial::Use(const PShader &shader)
{
  // Устанавливаем текстуру в шейдер.
  mTexture->Set(TEXTURE_SLOT_0);
  glUniform1i(shader->GetUniformLocation(make_str(mTexture)), TEXTURE_SLOT_0);
}

void SimpleMaterial::SetTexture(const PTexture &texture)
{
  mTexture = texture;
}

const PTexture &SimpleMaterial::GetTexture()
{
  return mTexture;
}
