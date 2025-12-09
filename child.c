#include "child.h"

int isGameOver(const GameStep step, Child child, const Wolf *wolf) {
  if (wolf->x == child.x && wolf->y == child.y ) { //si la position du loup est la même que la position de l'enfant alors
    child.etat = 0; // l'enfant se mourru
  } else if ( !((child.x >= FOREST_WIDTH || child.y >= FOREST_HEIGHT) || (child.x < 0 || child.y < 0))) { //sinon si l'enfant en dehors de forêt et s'echappe
    child.etat = 0; // enfant se mourru (mais s'est echapper genre il est pas mort pour de vrai)
  }
  return step == STEP_WOLF_MOVE;
}

void VerifyChildArea(Child *child, char forestMap[40][80], int dx[8], int dy[8], int *chosen) {for (int i = 0; i < 8; i++) {
    int r = rand() % 8; // choix d'une direction aléatoire

    int nx = child->x + dx[r];
    int ny = child->y + dy[r];

    // limiter à la map
    if (nx < 0 || ny < 0 || nx >= FOREST_WIDTH || ny >= FOREST_HEIGHT)
      continue;

    // si ce n’est pas un arbre → case valide
    if (forestMap[ny][nx] == ' ') {
      *chosen = r;
      break;
    }
  }
}

void moveChildStep(Child *child) {
   if (child->etat != 1) return; //si l'enfant est mort alors return
   char forestMap[FOREST_HEIGHT][FOREST_WIDTH];

  // 8 directions autour enfant
  int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; // x
  int dy[8] = {-1,-1,-1,  0, 0,  1, 1, 1}; // y

  int chosen = -1;

  // Vérifie des directions au hasard
  VerifyChildArea(child,forestMap,dx,dy,&chosen);
  // aucune direction libre trouvée
  if (chosen == -1) return;
  // déplacer l’enfant
  child->x += dx[chosen];
  child->y += dy[chosen];
}