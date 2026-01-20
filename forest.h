#ifndef __FOREST__H
#define __FOREST__H

#include "wolf.h"

/**
 * Custom type to encapsulate a Forest's behavior.
 * @author kheldae
 */
typedef struct {
  char f[FOREST_HEIGHT][FOREST_WIDTH];
} Forest;

/**
 * Forest constructor.
 * @param filepath the path of the file containing the forest
 * @return a fully formed Forest.
 * @pre @p filepath must be a valid path to a file we can open
 */
Forest *mk_forest(char *filepath);

/**
 * Forest removal function.
 * @param forest an existing Forest to delete.
 * @pre @p forest must be a valid pointer towards a Forest.
 */
void del_forest(Forest *forest);

/**
 * @param forest the Forest to look into.
 * @param x the x-coordinate of the tile we're looking for.
 * @param y the y-coordinate of the tile we're looking for.
 * @return the character contained in the tile we're looking for.
 * @pre @p forest must be a valid pointer towards a Forest.
 */
char get_tile(const Forest *forest, int x, int y);

#endif // __FOREST__H

// vim: ft=c.doxygen
