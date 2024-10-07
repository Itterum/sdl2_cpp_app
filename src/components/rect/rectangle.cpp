#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h) {
  point_x = x;
  point_y = y;
  width = w;
  height = h;
}

Rectangle::~Rectangle() {}

void Rectangle::shape(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  constexpr SDL_Rect rect = {100, 100, 200, 150};
  SDL_RenderFillRect(renderer, &rect);
}
