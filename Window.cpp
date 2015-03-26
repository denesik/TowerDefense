#include "Window.h"

#include <stdio.h>

Window::Window()
{
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  //glfwWindowHint(GLFW_SAMPLES, 4);

  GLFWmonitor *monitor = nullptr;

  mWindow = glfwCreateWindow(800, 600, "title", monitor, nullptr);
  if (!mWindow)
  {
    // Кинуть исключение
    return;
  }

  //glfwSwapInterval(0);
  printf("Window created\n");
}

Window::~Window()
{
  if(mWindow)
  {
    glfwDestroyWindow(mWindow);
  }
}

bool Window::WindowSystemInit()
{
  glfwSetErrorCallback([](int ,const char* description){printf("%s\n", description);});

  return glfwInit();
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
  glfwMakeContextCurrent(mWindow);
}

bool Window::WindowShouldClose()
{
  return glfwWindowShouldClose(mWindow);
}

void Window::SwapBuffers()
{
  glfwSwapBuffers(mWindow);
}






