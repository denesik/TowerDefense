#ifndef GAME_H
#define GAME_H

#include "Graphic/Window/IWindow.h"
#include "Graphic/Render/Render.h"

class Game
{
public:
  Game();
  ~Game();

  int Run();

private:

  bool Initialize();

  IWindow *mWindow;
  Render *mRender;

};

#endif // GAME_H
