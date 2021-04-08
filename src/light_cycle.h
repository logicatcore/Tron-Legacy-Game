#ifndef LIGHT_CYCLE_H
#define LIGHT_CYCLE_H

#include <vector>
#include "SDL.h"

class LightCycle {
 public:
  // enum will be same for kW, kS, kA, kD
  enum class Direction { kUp, kDown, kLeft, kRight };

  LightCycle(int grid_width, int grid_height, unsigned short player_no, LightCycle const &other)
      : grid_width(grid_width),
        grid_height(grid_height),
        apponent(other) {
          if (player_no == 1){
            head_x = 0;
            head_y = grid_height / 2 ;
            direction = Direction::kLeft;
          }
          else if (player_no == 2){
            head_x = grid_width;
            head_y = grid_height / 2;
            direction = Direction::kRight;
          }
        }

  LightCycle const &apponent;
  Direction direction;
  void Update();

  void GrowBody();

  float speed{0.1f};
  int score{0};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> trail;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif