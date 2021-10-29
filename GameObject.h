#ifndef __GameObject_H__
#define __GameObject_H__

#include "SDL.h"
#include "LoaderParams.h"
#include <iostream>

class GameObject
{
public:
  virtual void Draw() = 0;
  virtual void Update() = 0;
  virtual void Clean() = 0;

protected:
  GameObject(const LoaderParams* pParams) {}
};

#endif