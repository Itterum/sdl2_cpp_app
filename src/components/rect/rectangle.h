#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../shape/shape.h"
#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>

class Rectangle : public Shape {
public:
  Rectangle(int x, int y, int w, int h);
  ~Rectangle();

  void shape(SDL_Renderer *renderer) override;
};

#endif
