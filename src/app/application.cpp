#include "application.h"

Application::Application(const int width, const int height, const char *title) {
  w_width = width;
  w_height = height;
  w_title = title;
  init();
}

Application::~Application() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Application::init() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
  }
}

void Application::main_loop(SDL_Window *window, SDL_Renderer *renderer,
                            SDL_Texture *texture, std::vector<Shape *> &shapes,
                            bool animate) {
  bool quit = false;
  SDL_Event e;

  while (!quit) {
    // handle event SDL
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        quit = true;
      }
    }

    void *pixels = getPixels();
    int pitch = getPitch();

    lock_texture(texture, &pixels, &pitch);

    memset(pixels, 0, w_height * pitch);

    if (animate) {
      for (Shape *shape : shapes) {
        shape->animate(renderer, w_width, w_height);
      }
    }

    unlock_texture(texture);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);

    SDL_Delay(10);
  }

  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

SDL_Window *Application::create_window() {
  SDL_Window *window = SDL_CreateWindow(w_title.c_str(), 100, 100, w_width,
                                        w_height, SDL_WINDOW_SHOWN);

  if (window == nullptr) {
    std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
  }

  return window;
}

SDL_Renderer *Application::create_sdl_renderer(SDL_Window *window) {
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (renderer == nullptr) {
    std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
  }

  return renderer;
}

SDL_Texture *Application::create_sdl_texture(SDL_Renderer *renderer) {
  SDL_Texture *texture =
      SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                        SDL_TEXTUREACCESS_STREAMING, w_width, w_height);

  if (texture == nullptr) {
    std::cerr << "SDL_CreateTexture Error: " << SDL_GetError() << std::endl;
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
  }

  return texture;
}

void Application::lock_texture(SDL_Texture *texture, void **pixels,
                               int *pitch) {
  if (texture == nullptr) {
    std::cerr << "Texture is null!" << std::endl;
    return;
  }

  if (SDL_LockTexture(texture, nullptr, pixels, pitch) < 0) {
    std::cerr << "SDL_LockTexture Error: " << SDL_GetError() << std::endl;
  }
}

void Application::unlock_texture(SDL_Texture *texture) {
  if (texture == nullptr) {
    std::cerr << "Texture is null!" << std::endl;
    return;
  }

  SDL_UnlockTexture(texture);
}
