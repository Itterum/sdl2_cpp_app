#ifndef APPLICATION_H
#define APPLICATION_H

#include "../components/rect/rectangle.h"
#include <SDL2/SDL.h>
#include <cairo/cairo.h>
#include <cstddef>
#include <iostream>

class Application {
public:
  Application();
  ~Application();

  int init();
  void main_loop(SDL_Window *window, SDL_Renderer *renderer,
                 SDL_Texture *texture, Rectangle &rect, bool animate);
  void lock_texture(SDL_Texture *texture, void **pixels, int *pitch);
  void unlock_texture(SDL_Texture *texture);

  SDL_Window *create_window();
  SDL_Renderer *create_sdl_renderer(SDL_Window *window);
  SDL_Texture *create_sdl_texture(SDL_Renderer *render);

  void *getPixels() const { return pixels; }
  int getPitch() const { return pitch; }

private:
  void *pixels = nullptr;
  int pitch = 0;
};

#endif
