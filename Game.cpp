#include "Game.h"

#include "Graphic/Window/WindowGL.h"
#include "Graphic/Render/RenderErrorChecker.h"
#include <iostream>
#include <Graphic/Render/BoxMesh.h>
#include <Graphic/Render/Texture.h>
#include "Graphic/Render/SimpleMaterial.h"
#include "Graphic/Render/BaseMesh.h"
#include <Graphic/Render/CameraPersp.h>
#include "Graphic/Render/TextureManager.h"


Game::Game()
{
  mWindow = nullptr;
  mRender = nullptr;
}

Game::~Game()
{

}

bool Game::Initialize()
{
  WindowGL::WindowSystemInitialize();

  BoxMesh b;
  b.Generate();
  //Shader s("shaders/t2");

  try
  {
    mWindow = new WindowGL;
    mWindow->SetCurrentContext();
  }
  catch (WindowException *e)
  {
  	printf("%s\n", e->what());
    return false;
  }

  try
  {
    Render::Initialize();
  }
  catch (RenderException *e)
  {
    printf("%s\n", e->what());
    return false;
  }

  mRender = new Render;

  return true;
}

int Game::Run()
{
  if(!Initialize())
  {
    system("pause\n");
    return 0;
  }

  {
    PCameraPersp camera(new CameraPersp());

    TextureManager tm;
    tm.LoadTexture("textures/img.png");

    PTexture texture = tm.GetTexture("textures/img.png");

    PSimpleMaterial material(new SimpleMaterial());
    material->SetTexture(texture);

    PBoxMesh mesh(new BoxMesh());
    mesh->Generate();
    mesh->Create();

    PShader shader(new Shader("shaders/t2"));

    PModel model(new Model());
    model->SetMaterial(material);


    while(!mWindow->WindowShouldClose())
    {
      mRender->DrawModel(camera, model, glm::vec3(1.0f), glm::vec3(1.0f));

      mWindow->SwapBuffers();
      WindowGL::WindowSystemPollEvents();
    }
  }

  delete mRender;
  delete mWindow;
  WindowGL::WindowSystemFinally();

  system("pause\n");
  return 0;
}
