#ifndef GAME_H
#define GAME_H

#include <string>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "light_cycle.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  std::string GetScore() const;

 private:
  LightCycle cycle1, cycle2;

  void Update();
};

#endif