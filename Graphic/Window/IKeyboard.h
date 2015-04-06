#pragma once

#ifndef Keyboard_h__
#define Keyboard_h__

#include "Keys.h"

class IKeyboard
{
public:
  IKeyboard(){};
  ~IKeyboard(){};

  /// Была ли нажата клавиша.
  virtual bool IsKeyPress(Keys key) = 0;

  /// Клавиша отпущена?
  virtual bool IsKeyUp(Keys key) = 0;

  /// Клавиша нажата?
  virtual bool IsKeyDown(Keys key) = 0;
};


#endif // Keyboard_h__
