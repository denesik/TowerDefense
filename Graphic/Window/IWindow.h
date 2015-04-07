#pragma once

#ifndef Window_h__
#define Window_h__

#include <functional>
#include <glm/glm.hpp>
#include "IKeyboard.h"

class IWindow
{
public:
  IWindow(){};
  virtual ~IWindow(){};

  /// Установить текущий контекст для данного окна.
  virtual void SetCurrentContext() = 0;

  /// Должно ли окно закрыться?
  virtual bool WindowShouldClose() = 0;

  /// Переключить буферы.
  virtual void SwapBuffers() = 0;

  /// Получить клавиатуру.
  virtual const IKeyboard &GetKeyboard() = 0;

  /// Установить каллбек на событие изменение размеров окна.
  virtual void SetResizeCallback(std::function<void(glm::uvec2)> callback) = 0;
};

#endif // Window_h__
