#include "Game.h"

#include "Graphic/Window/WindowGL.h"
#include "Graphic/Render/RenderErrorChecker.h"
#include <iostream>
#include <Graphic/Render/BoxMesh.h>
#include <Graphic/Render/Texture.h>
#include "Graphic/Render/SimpleMaterial.h"
#include "Graphic/Render/BaseMesh.h"
#include <Graphic/Render/Camera.h>


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

  Camera *tmpCamera = new Camera();
  PCamera camera(tmpCamera);

  PTexture texture(new Texture(Bitmap("textures/img.png")));

  SimpleMaterial *tMaterial = new SimpleMaterial();
  tMaterial->SetTexture(texture);
  PMaterial material(tMaterial);

  BoxMesh *tMesh = new BoxMesh();
  tMesh->Generate();
  PMesh mesh(tMesh);
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

  delete mRender;
  delete mWindow;
  WindowGL::WindowSystemFinally();

  system("pause\n");
  return 0;
}
