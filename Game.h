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
  Game() {}
  ~Game() {}
  bool Init(const char* title, int x, int y, int w, int h, int flags);
  void Render();
  void Update();
  bool Running() const { return m_bRunning; }
  void HandleEvents();
  void Clean();

private:
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
  int m_currentFrame;
  std::vector<GameObject*> m_gameObjects;
};

#endif