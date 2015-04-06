#pragma once

#ifndef Keyboard_h__
#define Keyboard_h__

#include "Keys.h"

class IKeyboard
{
public:
  IKeyboard(){};
  ~IKeyboard(){};

  /// ���� �� ������ �������.
  virtual bool IsKeyPress(Keys key) = 0;

  /// ������� ��������?
  virtual bool IsKeyUp(Keys key) = 0;

  /// ������� ������?
  virtual bool IsKeyDown(Keys key) = 0;
};


#endif // Keyboard_h__
