#include "forest.h"
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

/**
 * @param step the current step of the game.
 * @param child the player's character.
 * @param wolf the big bad evil guy.
 * @return the new state of the game.
 * @pre @p wolf must be a valid pointer towards a Wolf struct.
 */
int isGameOver(GameStep step, Child child, const Wolf *wolf);

/**
 * @param child the player's character.
 * @param graph the map of explored forest tiles.
 * @param forest the forest we're exploring.
 * @pre @p child, @p graph and @p forest must be valid pointers towards their
 * respective structs.
 */
void moveChildStep(Child *child, Graph *graph, const Forest *forest);

#endif // WOLF__CHILD_H_

// vim: ft=c.doxygen
