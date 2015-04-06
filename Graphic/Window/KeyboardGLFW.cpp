#include "KeyboardGLFW.h"

#include <GLFW\glfw3.h>
#include "ConvertKeyGlfw.h"
#include <assert.h>

KeyboardGLFW::KeyboardGLFW()
  : mKeyState(GLFW_KEY_LAST + 1, GLFW_RELEASE)
{

}

KeyboardGLFW::~KeyboardGLFW()
{

}


void KeyboardGLFW::SetKey(int key, int scancode, int action, int mods)
{
  if(key == GLFW_KEY_UNKNOWN)
  {
    printf("glfw unknown key\n");
    return;
  }
  mKeyState[key] = action;
}

bool KeyboardGLFW::IsKeyPress(Keys key)
{
  assert(key != KEY_UNKNOWN);
  if(mKeyState[KeyToGlfw(key)] == GLFW_PRESS)
  {
    mKeyState[KeyToGlfw(key)] = GLFW_REPEAT;
    return true;
  }
  return false;
}

bool KeyboardGLFW::IsKeyUp(Keys key)
{
  assert(key != KEY_UNKNOWN);
  if(mKeyState[KeyToGlfw(key)] == GLFW_RELEASE)
    return true;
  return false;
}

bool KeyboardGLFW::IsKeyDown(Keys key)
{
  assert(key != KEY_UNKNOWN);
  if(mKeyState[KeyToGlfw(key)] == GLFW_REPEAT || mKeyState[KeyToGlfw(key)] == GLFW_PRESS)
    return true;
  return false;
}
