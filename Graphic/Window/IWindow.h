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

  /// ���������� ������� �������� ��� ������� ����.
  virtual void SetCurrentContext() = 0;

  /// ������ �� ���� ���������?
  virtual bool WindowShouldClose() = 0;

  /// ����������� ������.
  virtual void SwapBuffers() = 0;

  /// �������� ����������.
  virtual const IKeyboard &GetKeyboard() = 0;

  /// ���������� ������� �� ������� ��������� �������� ����.
  virtual void SetResizeCallback(std::function<void(glm::uvec2)> callback) = 0;
};

#endif // Window_h__
