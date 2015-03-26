#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>


class Window
{
public:
  Window();
  ~Window();

  /// Инициализация оконной системы.
  static bool WindowSystemInit();

  /// Завершить работу с оконной системой.
  static void WindowSystemTerminate();

  /// Обработать события.
  static void WindowSystemPollEvents();

  /// Установить текущий контекст для данного окна.
  void SetCurrentContext();

  /// Должно ли окно закрыться?
  bool WindowShouldClose();

  /// Переключить буферы.
  void SwapBuffers();

private:

  GLFWwindow *mWindow;

};

#endif // WINDOW_H
