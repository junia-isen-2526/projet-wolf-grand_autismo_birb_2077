#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int name;
  unsigned int x;
  unsigned int y;
} Point;

struct _st_graph {
  unsigned int nb_vertices;
  // TODO define containment
};

Graph *mk_graph() {
  Graph *graph = malloc(sizeof(Graph));
  // TODO
  return graph;
}

void del_graph(Graph *graph) {
  if (!graph)
    return; // silent fail in case of no pointer
  free(graph);
}

Graph *load_graph(FILE file);

void add_point(Graph *graph, unsigned int x, unsigned int y) {
  if (!graph)
    return; // silent fail
}

void graph2mmd(const Graph *graph, FILE file) {}

short is_in_graph(const Graph *graph, unsigned int x, unsigned int y) {
  return 0;
}
