#include "WindowGL.h"

#include <stdio.h>
#include <assert.h>

WindowGL::WindowGL()
  : mKeyboard(new KeyboardGLFW())
{
  printf("Start window creating\n");
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

  /// Привязываем к glfw окну указатель на объект WindowGL.
  glfwSetWindowUserPointer((mWindow.get()), this);

  //glfwSwapInterval(0);
  printf("Window created\n");
}

WindowGL::~WindowGL()
{
}

void WindowGL::GlfwErrorCallback(int ,const char* description)
{
  printf("glfw error: %s\n", description);
}

void WindowGL::GlfwKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
  WindowGL *windowGL = static_cast<WindowGL *>(glfwGetWindowUserPointer(window));
  if(windowGL)
  {
    windowGL->mKeyboard->SetKey(key, scancode, action, mods);
  }
}

void WindowGL::GlfwResizeCallback(GLFWwindow* window, int width, int height)
{
  WindowGL *windowGL = static_cast<WindowGL *>(glfwGetWindowUserPointer(window));
  if(windowGL && windowGL->mResizeCallback)
  {
    windowGL->mResizeCallback(glm::uvec2(width, height));
  }
}

void WindowGL::WindowSystemInitialize()
{
  //glfwSetErrorCallback([](int ,const char* description){printf("%s\n", description);});

  glfwSetErrorCallback(&GlfwErrorCallback);

  if (glfwInit() != GL_TRUE)
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

const IKeyboard &WindowGL::GetKeyboard()
{
  return *mKeyboard;
}

void WindowGL::SetResizeCallback(std::function<void(glm::uvec2)> callback)
{
  mResizeCallback = callback;
}






