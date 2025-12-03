#ifndef WOLF_GRAPH__H
#define WOLF_GRAPH__H

#include <stdio.h>

/**
 * Graph structure, hidden behind that inner API.
 * @author Khelda
 */
typedef struct _st_graph Graph;

/**
 * Empty graph builder. It may be useful to call this
 * before having to sort anything in.
 * @return a graph which knows no nodes.
 */
Graph *mk_graph();

/**
 * Graph deletion from memory.
 * @param graph the pointer towards the graph.
 * @pre @p graph must be not null.
 */
void del_graph(const Graph *graph);

/**
 * Graph loader from a file. The graph should know the
 * points listed in the file.
 * @param file the file descriptor we want to read from.
 * @return a new graph made from the file informations.
 * @rep @p file must point to an open JSON file
 */
Graph *load_graph(FILE file);

/**
 * Let the graph know of a "new" point. In case of already
 * known points, it will silentlty fail.
 * @param graph the graph we're writing on.
 * @param x the x-coordinate. It will not be checked.
 * @param y the y-coordinate. It will not be checked.
 * @warning in case of aberrant coordinates, the graph
 * may turn out... Weird.
 * @pre @p graph must be a valid pointer.
 */
void add_point(Graph *graph, int x, int y);

/**
 * Turning our graph into a mermaid string
 * @param graph the graph to transform.
 * @return a mermaid file content ready for output.
 * @pre @p graph must be a valid pointer.
 */
char *graph2mmd(const Graph *graph);

/**
 * @param graph
 * @param x
 * @param y
 * @return
 * @pre @p graph must be a valid pointer.
 */
short is_in_graph(const Graph *graph, int x, int y);

#endif // WOLF_GRAPH__H

// vim: ft=c.doxygen
