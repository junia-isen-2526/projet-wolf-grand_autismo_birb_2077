#include "child.h"

int isGameOver(const GameStep step, Child child, const Wolf *wolf) {
  if (wolf->x == child.y && wolf->y == child.x ) { //si la position du loup est la même que la position de l'enfant alors
    child.etat = 0; // l'enfant se mourru
  } else if ( !((child.x >= FOREST_WIDTH || child.y >= FOREST_HEIGHT) || (child.x < 0 || child.y < 0))) { //sinon si l'enfant en dehors de forêt et s'echappe
    child.etat = 0; // enfant se mourru (mais s'est echapper genre il est pas mort pour de vrai)
  }
  return step == STEP_WOLF_MOVE;
}

void moveChildStep(Child *child) {
  if (child->etat == 1) { //si enfant en vie alors
    int dx = (rand() % 3) - 1; // direction random x
    int dy = (rand() % 3) - 1; // direction random y
    child->x += dx; // nouvelle direction x
    child->y += dy; // nouvelle direction y
    //printf("'The Child' se déplace en (%d, %d)\n", child->x, child->y);
  }
}
