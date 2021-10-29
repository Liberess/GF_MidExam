#include "Game.h"

bool Game::Init(const char *title, int xpos, int ypos, int width, int height, int flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if (m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
      if (m_pRenderer != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

        SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/animate.bmp");
        if(pTempSurface != 0)
        {
          m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
          SDL_FreeSurface(pTempSurface);

          if(m_pTexture != 0)
          {
            m_desRect.x = m_srcRect.x = 0;
            m_desRect.y = m_srcRect.y = 0;
            m_desRect.w = m_srcRect.w = 128;
            m_desRect.h = m_srcRect.h = 82;
          }
          else
          {
            return false;
          }
        }
        else
        {
          return false;
        }
      }
      else
      {
        return false; // 랜더러 생성 실패
      }
    }
    else
    {
      return false; // 윈도우 생성 실패 l
    }
  }
  else
  {
    return false; // SDL 초기화 실패
  }

  m_bRunning = true;
  return true;
}

void Game::HandleEvents()
{
  SDL_Event event;
  if (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        m_bRunning = false;
        break;
      default:
        break;
    }
  }
}

void Game::Update()
{
  m_srcRect.x = 128 * ((SDL_GetTicks() / 100) % 6);
}

void Game::Render()
{
  SDL_RenderClear(m_pRenderer);
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_srcRect, &m_desRect);
  SDL_RenderPresent(m_pRenderer);
}

void Game::Clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}