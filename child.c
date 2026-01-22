#include "child.h"
#include "graph.h"

int isGameOver(const GameStep step, Child child, const Wolf *wolf) {
  if (wolf->x == child.x &&
      wolf->y == child.y) { // si la position du loup est la même que la
                            // position de l'enfant alors
    child.etat = 0;         // l'enfant se mourru
    // TODO return correct step
  } else if (!((child.x >= FOREST_WIDTH || child.y >= FOREST_HEIGHT) ||
               (child.x < 0 ||
                child.y <
                    0))) { // sinon si l'enfant en dehors de forêt et s'echappe
    child.etat = 0; // enfant se mourru (mais s'est echapper genre il est pas
                    // mort pour de vrai)
    // TODO return correct step
  }
  return step == STEP_WOLF_MOVE;
}

void moveChildStep(Child *child, Graph *graph, const Forest *forest) {
  if (!child || !graph)
    return; // pointer issue, there is no child or no graph

  // define child starting point in case it's needed
  // this should only be fired once
  if (child->x == -1 || child->y == -1) {
    for (int y = 0; y < FOREST_HEIGHT; y++)
      for (int x = 0; x < FOREST_WIDTH; x++) {
        if (is_in_graph(graph, x, y))
          continue; // already known starting point

        if (!(y == 0 || y == FOREST_HEIGHT - 1) &&
            !(x == 0 || x == FOREST_WIDTH - 1))
          continue; // not a valid starting spot

        // found an entry point
        if (get_tile(forest, x, y) == ' ') {
          child->x = x;
          child->y = y;
        }
      }
  }

  if (child->etat != 1)
    return; // si l'enfant est mort alors return

  // 8 directions autour enfant
  int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; // x
  int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; // y

  int chosen = -1;

  // Vérifie des directions au hasard
  for (int i = 0; i < 8; i++) {
    int r = rand() % 8; // choix d'une direction aléatoire

    int nx = child->x + dx[r];
    int ny = child->y + dy[r];

    // limiter à la map
    if (nx < 0 || ny < 0 || nx >= FOREST_WIDTH || ny >= FOREST_HEIGHT)
      continue;

    // si ce n’est pas un arbre → case valide
    if (get_tile(forest, ny, nx) == ' ') {
      chosen = r;
      break;
    }

    if (is_in_graph(graph, nx, ny))
      continue; // already visited that tile
  }
  // aucune direction libre trouvée
  if (chosen == -1)
    return;
  // coords cache
  int tx = child->x;
  int ty = child->y;
  // déplacer l’enfant
  child->x += dx[chosen];
  child->y += dy[chosen];
  // save to graph (we visited that point)
  add_edge(graph, tx, ty, child->x, child->y);
}
