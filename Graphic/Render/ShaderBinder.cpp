#include "ShaderBinder.h"
#include <assert.h>


ShaderBinder::ShaderBinder(const PMaterial &material, const PShader &shader)
  : mMaterial(material), mShader(shader)
{
  assert(material && shader);
}


ShaderBinder::~ShaderBinder()
{
}

void ShaderBinder::CreateUniform(unsigned int index, const char *name)
{
  if(index >= mUniforms.size())
  {
    mUniforms.resize(index + 1, -1);
  }
  mUniforms[index] = mShader->GetUniformLocation(name);
}

int ShaderBinder::GetUniformLocation(unsigned int index)
{
  assert(index < mUniforms.size());
  return mUniforms[index];
}
