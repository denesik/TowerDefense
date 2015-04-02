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

}

const PMaterial &Model::GetMaterial()
{
  return mMaterial;
}

void Model::SetMaterial(const PMaterial &material)
{

}

const PShader &Model::GetShader()
{
  return mShader;
}

void Model::GetShader(const PShader &shader)
{

}

