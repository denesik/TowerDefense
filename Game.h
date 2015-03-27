#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Render.h"

class Game
{
public:
  Game();
  ~Game();

  int Run();

private:

  bool Initialize();

  Window *mWindow;
  Render *mRender;

};

#endif // GAME_H
