#include "Model.h"

Model::Model()
{

}

Model::~Model()
{

}

const PMesh &Model::GetMesh()
{
  return mMesh;
}

void Model::SetMesh(const PMesh &mesh)
{
  mMesh = mesh;
}

const PMaterial &Model::GetMaterial()
{
  return mMaterial;
}

void Model::SetMaterial(const PMaterial &material)
{
  mMaterial = material;
}

const PShader &Model::GetShader()
{
  return mShader;
}

void Model::SetShader(const PShader &shader)
{
  mShader = shader;
}

