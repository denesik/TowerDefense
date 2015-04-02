#pragma once

#ifndef Keyboard_h__
#define Keyboard_h__

#include <vector>
#include "Keys.h"

class Keyboard
{
public:
  Keyboard();
  ~Keyboard();

  void SetKey(int key, int scancode, int action, int mods);

  bool isKeyPress(int key);
  bool isKeyUp(int key);
  bool isKeyDown(int key);

private:

  enum
  {
    KEY_RELEASE,
    KEY_PRESS,
    KEY_REPEAT,
  };

  std::vector<int> mKeyState;

};


#endif // Keyboard_h__
