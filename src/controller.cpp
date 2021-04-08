#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "light_cycle.h"

void Controller::ChangeDirection(LightCycle &lightCycle, LightCycle::Direction input,
                                 LightCycle::Direction opposite) const {
  if (lightCycle.direction != opposite) lightCycle.direction = input;
  return;
}

void Controller::HandleInput(bool &running, LightCycle &lightCycle1, LightCycle &lightCycle2) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        // direction controls for player 1 and 2
        // upwards turns
        case SDLK_w:
          ChangeDirection(lightCycle2, LightCycle::Direction::kUp,
                          LightCycle::Direction::kDown);
          break;
        case SDLK_UP:
          ChangeDirection(lightCycle1, LightCycle::Direction::kUp,
                          LightCycle::Direction::kDown);
          break;
        // downwards turns
        case SDLK_s:
          ChangeDirection(lightCycle2, LightCycle::Direction::kDown,
                          LightCycle::Direction::kUp);
          break;
        case SDLK_DOWN:
          ChangeDirection(lightCycle1, LightCycle::Direction::kDown,
                          LightCycle::Direction::kUp);
          break;
        // lefttwards turns
        case SDLK_a:
          ChangeDirection(lightCycle2, LightCycle::Direction::kLeft,
                          LightCycle::Direction::kRight);
          break;
        case SDLK_LEFT:
          ChangeDirection(lightCycle1, LightCycle::Direction::kLeft,
                          LightCycle::Direction::kRight);
          break;
        // rightwards turns
        case SDLK_d:
          ChangeDirection(lightCycle2, LightCycle::Direction::kRight,
                          LightCycle::Direction::kLeft);
          break;
        case SDLK_RIGHT:
          ChangeDirection(lightCycle1, LightCycle::Direction::kRight,
                          LightCycle::Direction::kLeft);
          break;
        // speed controls for player 1 and 2
        // q -> quicker
        case SDLK_q:
          lightCycle2.speed += 0.05;
          break;
        // '/' (forward slash) because nearest key to arrows
        case SDLK_SLASH:
          lightCycle1.speed += 0.05;
          break;
      }
    }
  }
}