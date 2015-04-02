#include "Keyboard.h"

#include <GLFW\glfw3.h>
#include "ConvertKey.h"

Keyboard::Keyboard()
  : mKeyState(KEYS_COUNT, KEY_RELEASE)
{

}

Keyboard::~Keyboard()
{

}


void Keyboard::SetKey(int key, int scancode, int action, int mods)
{
  mKeyState[key] = KeyTo(action);
}

bool Keyboard::isKeyPress( int key )
{
  if(mKeyState[key] == KEY_PRESS)
  {
    mKeyState[key] = KEY_REPEAT;
    return true;
  }
  return false;
}

bool Keyboard::isKeyUp( int key )
{
  if(mKeyState[key] == KEY_RELEASE)
    return true;
  return false;
}

bool Keyboard::isKeyDown( int key )
{
  if(mKeyState[key] == KEY_REPEAT || mKeyState[key] == KEY_PRESS)
    return true;
  return false;
}
