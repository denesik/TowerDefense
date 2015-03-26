#ifndef GAME_H
#define GAME_H

#include "Window.h"

class Game
{
public:
  Game();
  ~Game();

  int Run();

private:

  bool Initialize();

  Window *mWindow;

};

#endif // GAME_H
