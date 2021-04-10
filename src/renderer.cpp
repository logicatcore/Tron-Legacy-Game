#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Tron Legacy Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(LightCycle const &lightCycle1, LightCycle const &lightCycle2 ) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);

  // tron blue trail
  SDL_SetRenderDrawColor(sdl_renderer, 0x66, 0xFB, 0xFB, 0xFF);
  for (SDL_Point const &point : lightCycle1.trail) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }
  // tron orange trail
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xA5, 0x00, 0xFF);
  for (SDL_Point const &point : lightCycle2.trail) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // tron vehicle
  block.x = static_cast<int>(lightCycle1.head_x) * block.w;
  block.y = static_cast<int>(lightCycle1.head_y) * block.h;
  if (lightCycle1.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x04, 0x94, 0x94, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // tron vehicle
  block.x = static_cast<int>(lightCycle2.head_x) * block.w;
  block.y = static_cast<int>(lightCycle2.head_y) * block.h;
  if (lightCycle2.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0xCC, 0x84, 0x00, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score1, int score2, int fps) {
  std::string title{"PL1 Score: " + std::to_string(score1) + "| PL2 Score: " + std::to_string(score2) + "| FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
