#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "light_cycle.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(LightCycle const &lightCycle1, LightCycle const &lightCycle2);
  void UpdateWindowTitle(int score1, int score2, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif