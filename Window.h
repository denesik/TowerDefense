#pragma once

#ifndef Window_h__
#define Window_h__

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
};

#endif // Window_h__
