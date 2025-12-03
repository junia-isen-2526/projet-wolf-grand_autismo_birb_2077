#include "wolf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef WOLF__CHILD_H_
#define WOLF__CHILD_H_

typedef struct {
  // TODO
} Child;

int isGameOver(GameStep step, Child child, const Wolf *wolf);

void moveChildStep(const Child *child);

#endif // WOLF__CHILD_H_
