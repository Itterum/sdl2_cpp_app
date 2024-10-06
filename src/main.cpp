#include "app/application.h"
#include "components/rect/rectangle.h"

int main(int argc, char *argv[]) {
  Application app;

  SDL_Window *window = app.create_window();
  SDL_Renderer *renderer = app.create_sdl_renderer(window);
  SDL_Texture *texture = app.create_sdl_texture(renderer);

  if (!texture) {
    std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
    return -1;
  }

  void *pixels = app.getPixels();
  int pitch = app.getPitch();

  app.lock_texture(texture, &pixels, &pitch);

  Rectangle rect(100, 100, 32, 32);
  rect.draw(pixels, pitch);

  app.unlock_texture(texture);

  app.main_loop(window, renderer, texture);

  return 0;
}
