#include "Game.h"

#include "RenderErrorChecker.h"
#include <iostream>


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
  Window::WindowSystemInit();

  try
  {
    mWindow = new Window;
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

  while(!mWindow->WindowShouldClose())
  {

    mRender->Draw();

    mWindow->SwapBuffers();
    Window::WindowSystemPollEvents();
  }

  delete mRender;
  delete mWindow;
  Window::WindowSystemTerminate();

  system("pause\n");
  return 0;
}
