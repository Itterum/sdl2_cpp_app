#include "app/application.h"
#include "components/circle/circle.h"
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

  std::vector<Shape *> shapes;

  Rectangle rect(50, 50, 32, 32);
  Circle circle(100, 100, 50, 50);

  shapes.push_back(&rect);
  shapes.push_back(&circle);

  app.unlock_texture(texture);

  app.main_loop(window, renderer, texture, shapes, true);

  return 0;
}
