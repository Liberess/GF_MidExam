#ifndef __Game_H__
#define __Game_H__

#include "SDL.h"
#include "GameObject.h"
#include "TextureManager.h"
#include <vector>
#include <iostream>

class Game
{
public:
  static Game* Instance()
  {
    if(s_pInstance == 0)
      s_pInstance = new Game();

    return s_pInstance;
  }
  bool Init(const char* title, int x, int y, int w, int h, int flags);
  void Render();
  void Update();
  bool Running() const { return m_bRunning; }
  SDL_Renderer* GetRenderer() const { return m_pRenderer; }
  void HandleEvents();
  void Clean();

private:
  Game() {}
  ~Game() {}
  static Game* s_pInstance;
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
  int m_currentFrame;
  std::vector<GameObject*> m_gameObjects;
};

typedef Game TheGame;

#endif