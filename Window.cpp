#include "Window.h"

#include <stdio.h>
#include <assert.h>

Window::Window()
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

Window::~Window()
{
}

void Window::WindowSystemInit()
{
  glfwSetErrorCallback([](int ,const char* description){printf("%s\n", description);});

  if(glfwInit() != GL_TRUE)
  {
    throw new WindowException(WindowException::WINDOW_SYSTEM_NOT_INICIALIZED);
  }
}

void Window::WindowSystemTerminate()
{
  glfwTerminate();
}

void Window::WindowSystemPollEvents()
{
  glfwPollEvents();
}

void Window::SetCurrentContext()
{
  assert(mWindow);
  glfwMakeContextCurrent(mWindow.get());
}

bool Window::WindowShouldClose()
{
  assert(mWindow);
  return glfwWindowShouldClose(mWindow.get()) == GL_TRUE;
}

void Window::SwapBuffers()
{
  assert(mWindow);
  glfwSwapBuffers(mWindow.get());
}






