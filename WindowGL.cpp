#include "WindowGL.h"

#include <stdio.h>
#include <assert.h>

WindowGL::WindowGL()
{
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  //glfwWindowHint(GLFW_SAMPLES, 4);

  GLFWmonitor *monitor = nullptr;

  mWindow = (decltype(mWindow))(glfwCreateWindow(800, 600, "title", monitor, nullptr));

  if (!mWindow)
  {
    throw new WindowException(WindowException::NOT_CREATED);
  }

  //glfwSwapInterval(0);
  printf("Window created\n");
}

WindowGL::~WindowGL()
{
}

void glfwErrorCallback(int ,const char* description)
{
  printf("%s\n", description);
}

void WindowGL::WindowSystemInitialize()
{
  //glfwSetErrorCallback([](int ,const char* description){printf("%s\n", description);});

  glfwSetErrorCallback(&glfwErrorCallback);

  if(glfwInit() != GL_TRUE)
  {
    throw new WindowException(WindowException::WINDOW_SYSTEM_NOT_INICIALIZED);
  }
}

void WindowGL::WindowSystemFinally()
{
  glfwTerminate();
}

void WindowGL::WindowSystemPollEvents()
{
  glfwPollEvents();
}

void WindowGL::SetCurrentContext()
{
  assert(mWindow);
  glfwMakeContextCurrent(mWindow.get());
}

bool WindowGL::WindowShouldClose()
{
  assert(mWindow);
  return glfwWindowShouldClose(mWindow.get()) == GL_TRUE;
}

void WindowGL::SwapBuffers()
{
  assert(mWindow);
  glfwSwapBuffers(mWindow.get());
}






