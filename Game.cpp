#include "Game.h"


Game::Game()
{
  mWindow = nullptr;
}

Game::~Game()
{

}

bool Game::Initialize()
{
  if(!Window::WindowSystemInit())
  {
    return false;
  }

  mWindow = new Window;

  return true;
}

int Game::Run()
{
  if(!Initialize())
  {
    return 0;
  }

  while(!mWindow->WindowShouldClose())
  {

    mWindow->SwapBuffers();
    Window::WindowSystemPollEvents();
  }

  delete mWindow;
  Window::WindowSystemTerminate();

  return 0;
}
