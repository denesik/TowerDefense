#pragma once

#ifndef ShaderBinder_h__
#define ShaderBinder_h__

#include <vector>
#include "Shader.h"
#include "IMaterial.h"

/// Биндер параметров в шейдер.
class ShaderBinder
{
public:
  ShaderBinder(const PMaterial &material, const PShader &shader);
  ~ShaderBinder();

  void CreateUniform(unsigned int index, const char *name);

  int GetUniformLocation(unsigned int index);

private:

  //PMesh mMesh;
  PMaterial mMaterial;
  PShader mShader;

  std::vector<int> mUniforms;

};



#endif // ShaderBinder_h__
