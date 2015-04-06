#ifndef WINDOW_GL_H
#define WINDOW_GL_H

#include "IWindow.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>
#include "KeyboardGLFW.h"

class WindowException: public std::exception
{
public:
  WindowException(unsigned int id)
    : mId(id)
  {
  }
  virtual const char *what() const throw()
  {
    return "Window exception";
  }

  enum
  {
    WINDOW_SYSTEM_NOT_INICIALIZED,
    NOT_CREATED,

    COUNT,
  };

private:
  const unsigned int mId;
};


class WindowGL : public IWindow
{
public:
  WindowGL();
  ~WindowGL();

  /// Инициализация оконной системы.
  static void WindowSystemInitialize();

  /// Завершить работу с оконной системой.
  static void WindowSystemFinally();

  /// Обработать события.
  static void WindowSystemPollEvents();

  /// Установить текущий контекст для данного окна.
  void SetCurrentContext() override;

  /// Должно ли окно закрыться?
  bool WindowShouldClose() override;

  /// Переключить буферы.
  void SwapBuffers() override;

  const IKeyboard &GetKeyboard() override;

private:

  struct WindowDeleter
  {
    void operator()(GLFWwindow *window) const
    {
      printf("window delete\n");
      glfwDestroyWindow(window);
    }
  };

  std::unique_ptr<GLFWwindow, WindowDeleter> mWindow;

  std::unique_ptr<KeyboardGLFW> mKeyboard;


  // Функции обратного вызова для glfw.
  static void GlfwErrorCallback(int ,const char* description);
  static void GlfwKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

};

#endif // WINDOW_GL_H
