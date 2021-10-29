#include <SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false; //게임 중? 아님?

int main(int argc, char* args[]);
bool Init(const char* title, int x, int y, int w, int h, int flags);
void Update();
void Render();

int main(int argc, char* args[])
{
  if(Init("Breaking Up HelloSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN))
  {
    g_bRunning = true;
  }
  else
  {
    return 1;
  }

  while(g_bRunning)
  {
    Update();
    Render();
    SDL_Delay(1000);
  }

  SDL_Quit();

  return 0;
}

bool Init(const char* title, int x, int y, int w, int h, int flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    g_pWindow = SDL_CreateWindow(title, x, y, w, h, flags);

    if (g_pWindow != 0)
    {
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    }
  }
  else
  {
    return 1;
  }

  SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 0);
}

void Update()
{
  static int count = 0;

  if(count >= 3)
  {
    g_bRunning = false;
    return;
  }

  ++count;
}

void Render()
{
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);
}