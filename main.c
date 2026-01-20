#include "child.h"
#include "graph.h"
#include "wolf.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Some constants (notably filenames)
#define FILENAME "../mmd/wolfie.mmd"
#define FOREST_FILE                                                            \
  "../ressources/foret2.txt" // change it for your preferred forest

int main() {
  srand(time(NULL));

  char rhyme[MAXLines][MAX_LINE_LENGTH];
  const int rhymeCount = readLines("../ressources/comptine.txt", rhyme);

  char clothes[MAXClothes][MAX_LINE_LENGTH];
  const int clothesCount = readLines("../ressources/vetements.txt", clothes);

  // graph initialisation
  Graph *graph = mk_graph();

  Wolf wolf = {-1, -1, 0};
  Child child;

  // avoiding defaults on the kid
  child.x = -1;
  child.y = -1;

  GameStep step = STEP_COMPTINE;

  while (!isGameOver(step, child, &wolf)) {
    switch (step) {
    case STEP_COMPTINE:
      if (playComptineStep(rhyme, rhymeCount))
        step = STEP_DRESSING;
      break;
    case STEP_DRESSING:
      if (wolfDressingStep(&wolf, clothes, clothesCount)) {
        step = STEP_WOLF_MOVE;
      } else {
        step = STEP_COMPTINE;
      }
      break;
    case STEP_WOLF_MOVE:
      moveWolfStep(&wolf);
      break;
    }
    moveChildStep(&child, graph);
  }

  // saving graph to mermaid file
  FILE *mmd_file = fopen(FILENAME, "w");
  graph2mmd(graph, mmd_file);
  fclose(mmd_file);

  // cleanup phase
  del_graph(graph);

  return 0;
}
