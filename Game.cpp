#include "Game.h"

#include "RenderErrorChecker.h"
#include <iostream>


Game::Game()
{
  mWindow = nullptr;
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
  }
  catch (WindowException* e)
  {
  	printf("%s\n", e->what());
    return false;
  }

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

    mWindow->SwapBuffers();
    Window::WindowSystemPollEvents();
  }

  delete mWindow;
  Window::WindowSystemTerminate();

  system("pause\n");
  return 0;
}
