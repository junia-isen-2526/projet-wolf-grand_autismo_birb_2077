#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int name;
  unsigned int x;
  unsigned int y;
} Point;

typedef struct st_edge Edge;

struct st_edge {
  Point *a;
  Point *b;
  // linked list stuff
  Edge *next;
};

struct _st_graph {
  unsigned int nb_vertices;
  Edge *edges;
  // keeping current point in mind
  Point *point;
};

Graph *mk_graph() {
  Graph *graph = malloc(sizeof(Graph));
  graph->nb_vertices = 0;
  graph->edges = 0; // no known edges for now
  graph->point = 0;
  return graph;
}

void del_edge(Edge *e) {
  if (!e)
    return;
  del_edge(e->next);
  free(e);
}

void del_graph(Graph *graph) {
  if (!graph)
    return; // silent fail in case of no pointer
  del_edge(graph->edges);
  free(graph->point);
  free(graph);
}

Graph *load_graph(FILE *file) {
  if (!file)
    return 0; // not my problem
  return 0;
}

void add_point(Graph *graph, unsigned int x, unsigned int y) {
  if (!graph)
    return; // silent fail
}

void graph2mmd(const Graph *graph, FILE *file) {
  if (!graph || !file)
    return; // not my problem then
  fprintf(file, "TD");
  for (Edge *e = graph->edges; e; e = e->next) {
    fprintf(file, ""); // TODO find what to print
  }
}

short is_in_graph(const Graph *graph, unsigned int x, unsigned int y) {
  return 0;
}
