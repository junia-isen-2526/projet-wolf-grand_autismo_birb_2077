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
void del_graph(Graph *graph);

/**
 * Graph loader from a file. The graph should know the
 * points listed in the file.
 * @param file the file descriptor we want to read from.
 * @return a new graph made from the file informations.
 * @rep @p file must point to an open Mermaid file with content in it.
 * @warning in case of malformed mermaid file, this will return a null pointer.
 * You shouldn't bother continuing, this is an aberrant scenario.
 */
Graph *load_graph(FILE *file);

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
void add_point(Graph *graph, unsigned int x, unsigned int y);

/**
 * @param graph the graph to insert into.
 * @param ax the x-coordinate of the point to start from.
 * @param ay the y-coordinate of the point to start from.
 * @param bx the x-coordinate of the end of the edge.
 * @param by the y-coordinate of the end of the edge.
 * @pre @p graph must be a valid pointer towards a graph structure.
 */
void add_edge(Graph *graph, unsigned int ax, unsigned int ay, unsigned int bx,
              unsigned by);

/**
 * Turning our graph into a mermaid string
 * @param graph the graph to transform.
 * @param file the file to which we want to write the graph.
 * @pre @p graph must be a valid pointer.
 * @pre @p file must be a valid file descriptor to an opened file.
 */
void graph2mmd(const Graph *graph, FILE *file);

/**
 * @param graph the graph to check into.
 * @param x the x-coordinate of the point to search for.
 * @param y the y-coordinate of the point to search for.
 * @return 1 if the point is in the graph, 0 otherwise.
 * @pre @p graph must be a valid pointer.
 */
int is_in_graph(const Graph *graph, unsigned int x, unsigned int y);

#endif // WOLF_GRAPH__H

// vim: ft=c.doxygen
