#include "graph.h"
#include "wolf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef WOLF__CHILD_H_
#define WOLF__CHILD_H_

typedef struct {
  unsigned int x;
  unsigned int y;
  unsigned int etat; // 0 = FAUX, 1 = VRAI faut penser à faire attention à qu'il
                     // ne va pas au dessus de 1
} Child;

int isGameOver(GameStep step, Child child, const Wolf *wolf);

void moveChildStep(Child *child, Graph *graph);

#endif // WOLF__CHILD_H_
