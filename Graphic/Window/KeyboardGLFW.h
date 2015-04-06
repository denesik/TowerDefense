#pragma once

#ifndef Keyboard_GLFW_h__
#define Keyboard_GLFW_h__

#include <vector>
#include "IKeyboard.h"

class KeyboardGLFW : public IKeyboard
{
public:
  KeyboardGLFW();
  ~KeyboardGLFW();

  void SetKey(int key, int scancode, int action, int mods);

  bool IsKeyPress(Keys key) override;
  bool IsKeyUp(Keys key) override;
  bool IsKeyDown(Keys key) override;

private:

  std::vector<int> mKeyState;
};


#endif // Keyboard_GLFW_h__
