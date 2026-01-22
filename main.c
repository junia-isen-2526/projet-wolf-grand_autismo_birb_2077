#include "child.h"
#include "forest.h"
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
  Graph *graph;
  FILE *file = fopen(FILENAME, "r");
  if (file) {
    graph = load_graph(file);
    fclose(file);
  } else
    graph = mk_graph();

  Wolf wolf = {-1, -1, 0};

  // avoiding defaults on the kid
  Child child;
  child.x = -1;
  child.y = -1;

  // fetching forest (no post-mk checks)
  Forest *forest = mk_forest(FOREST_FILE);

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
    moveChildStep(&child, graph, forest);
  }

  // saving graph to mermaid file
  FILE *mmd_file = fopen(FILENAME, "w");
  graph2mmd(graph, mmd_file);
  fclose(mmd_file);

  // cleanup phase
  del_graph(graph);
  del_forest(forest);

  return 0;
}
