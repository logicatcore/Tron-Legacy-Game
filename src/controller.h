#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "light_cycle.h"

class Controller {
 public:
  void HandleInput(bool &running, LightCycle &lightCycle1, LightCycle &lightCycle2) const;

 private:
  void ChangeDirection(LightCycle &lightCycle, LightCycle::Direction input,
                       LightCycle::Direction opposite) const;
};

#endif