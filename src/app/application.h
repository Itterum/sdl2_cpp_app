#ifndef APPLICATION_H
#define APPLICATION_H

#include "../components/shape/shape.h"
#include <SDL2/SDL.h>
#include <cstddef>
#include <iostream>
#include <vector>

class Application {
public:
  Application(int width, int height, const char *title);
  ~Application();

  void init();
  void main_loop(SDL_Window *window, SDL_Renderer *renderer,
                 SDL_Texture *texture, std::vector<Shape *> &shapes,
                 bool animate);
  void lock_texture(SDL_Texture *texture, void **pixels, int *pitch);
  void unlock_texture(SDL_Texture *texture);

  SDL_Window *create_window();
  SDL_Renderer *create_sdl_renderer(SDL_Window *window);
  SDL_Texture *create_sdl_texture(SDL_Renderer *render);

  void *getPixels() const { return pixels; }
  int getPitch() const { return pitch; }

private:
  void *pixels = nullptr;
  int pitch, w_height, w_width = 0;
  std::string w_title;
  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;
};

#endif
