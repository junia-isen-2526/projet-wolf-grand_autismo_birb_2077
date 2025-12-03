#include "child.h"

int isGameOver(const GameStep step, Child child, const Wolf *wolf) {
  if (wolf->x == child.y && wolf->y == child.x ) {
    child.etat = 0;
  } else if ( !((child.x >= FOREST_WIDTH || child.y >= FOREST_HEIGHT) || (child.x >= 0 || child.y >= 0))) {
    child.etat = 0;
  }
  return step == STEP_WOLF_MOVE;
}

void moveChildStep(const Child *child) {
  // TODO
}
