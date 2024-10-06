#include "application.h"

Application::Application() { init(); }

Application::~Application() {
  if (pixels) {
    free(pixels);
  }
  SDL_Quit();
}

int Application::init() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  return 0;
}

void Application::main_loop(SDL_Window *window, SDL_Renderer *renderer,
                            SDL_Texture *texture, Rectangle &rect,
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

    memset(pixels, 0, 480 * pitch);

    if (animate) {
      rect.animate(pixels, pitch, 640, 480);
    }

    unlock_texture(texture);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_Delay(10);
  }

  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

SDL_Window *Application::create_window() {
  SDL_Window *window =
      SDL_CreateWindow("Cairo with SDL2", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

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
                        SDL_TEXTUREACCESS_STREAMING, 640, 480);

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

  if (SDL_LockTexture(texture, NULL, pixels, pitch) < 0) {
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
