#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct st_point Point;

struct st_point {
  unsigned int name;
  unsigned int x;
  unsigned int y;
  // link list of points
  Point *next;
};

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
  Point *points;
};

Graph *mk_graph() {
  Graph *graph = malloc(sizeof(Graph));
  graph->nb_vertices = 0;
  graph->edges = 0;  // no known edges for now
  graph->points = 0; // no known points for now
  return graph;
}

void del_edges(Edge *e) {
  if (!e)
    return;
  del_edges(e->next);
  free(e);
}

void del_points(Point *p) {
  if (!p)
    return;
  del_points(p);
  free(p);
}

void del_graph(Graph *graph) {
  if (!graph)
    return; // silent fail in case of no pointer
  del_edges(graph->edges);
  del_points(graph->points);
  free(graph);
}

Graph *load_graph(FILE *file) {
  if (!file)
    return 0; // not my problem
  return 0;
}

// unique id generator
unsigned int get_id() {
  static long nextId = 0;
  return ++nextId;
}

// inner add method for graphs
void add_vertex(Graph *graph, unsigned int id, unsigned int x, unsigned int y) {
  if (!graph)
    return;
  // seeking an existing point
  Point *p = graph->points;
  for (p = graph->points; p; p = p->next)
    if (p->name == id)
      return; // the point already exist
  Point *pp = malloc(sizeof(Point));
  pp->name = id;
  pp->x = x;
  pp->y = y;
  if (!p) // no points yet
    p = pp;
  else
    p->next = pp;
}

void add_point(Graph *graph, unsigned int x, unsigned int y) {
  if (!graph)
    return; // silent fail
  add_vertex(graph, get_id(), x, y);
}

void graph2mmd(const Graph *graph, FILE *file) {
  if (!graph || !file)
    return; // not my problem then
  short known[graph->nb_vertices];
  for (int i = 0; i < graph->nb_vertices; i++)
    known[i] = 0;
  // actual writing
  fprintf(file, "graph TD");
  for (Edge *e = graph->edges; e; e = e->next) {
    fputc('\t', file);
    // TODO
    fprintf(file, " -> ");
    fputc('\n', file);
  }
}

short is_in_graph(const Graph *graph, unsigned int x, unsigned int y) {
  return 0;
}
