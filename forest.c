#include "forest.h"

#include <stdio.h>
#include <stdlib.h>

Forest *mk_forest(char *filepath) {
  if (!filepath)
    return 0; // no filename
  FILE *file = fopen(filepath, "r");
  // defining constants
  unsigned int x = 0;
  unsigned int y = 0;
  // building forest
  Forest *forest = malloc(sizeof(Forest));
  char *line;
  while (fscanf(file, "%s\n", line))
    for (int i = 0; line[i] != '\0'; i++) {
      forest->f[y][x] = line[i];
      // handling increments
      if (x == FOREST_WIDTH - 1)
        y++; // no modulo reset for this
      x = (x + 1) % FOREST_WIDTH;
    }
  // cleanup
  fclose(file);
  return forest;
}

void del_forest(Forest *forest) {
  if (!forest)
    return; // nonsense
  free(forest);
}

char get_tile(const Forest *forest, int x, int y) {
  if (!forest)
    return ' '; // returning aberration
  return forest->f[y % FOREST_HEIGHT][x % FOREST_WIDTH];
}
