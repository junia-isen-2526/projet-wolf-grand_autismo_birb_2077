#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  unsigned int a;
  unsigned int b;
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

// TODO add point parsing function. Non-const pointers are used as outs.
short parse_point(char str[], int *name, int *x, int *y) {
  if (strlen(str) == 0)
    return 0; // there is nothing to parse
  char *slice = strtok(str, "(,)");
  *name = atoi(slice);
  slice = strtok(NULL, "(,)");
  // TODO check if we have the others
  if (!slice)
    return 1; // no inner info to the point
  *x = atoi(slice);
  // TODO check y
  slice = strtok(NULL, "(,)");
  if (!slice)
    return 0; // this is not normal
  *y = atoi(slice);
  return 1;
}

Graph *load_graph(FILE *file) {
  if (!file)
    return 0; // not my problem
  Graph *graph = mk_graph();
  // start parsing
  char *a_str; // inner point infos
  char *b_str; // inner point infos
  while (fscanf(file, "%s -> %s\n", a_str, b_str)) {
    // TODO parse strings
    if (!(graph->points))
      add_point(graph, 0, 0); // FIXME parse coordinates
    if (!is_in_graph(graph, 0, 0)) {
      del_graph(graph);
      return 0; // something has gone horribly wrong
    }
    // TODO add edges from the graph
  }
  return graph;
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
  graph->nb_vertices++;
}

void add_point(Graph *graph, unsigned int x, unsigned int y) {
  if (!graph)
    return; // silent fail
  add_vertex(graph, get_id(), x, y);
}

Point *get_vertex(const Graph *graph, unsigned int id) {
  for (Point *p = graph->points; p; p = p->next)
    if (p->name == id)
      return p;
  return 0;
}

void add_edge(Graph *graph, unsigned int ax, unsigned int ay, unsigned int bx,
              unsigned int by) {
  if (!graph || (ax == bx && ay == by))
    return; // silent fail
  unsigned int a = is_in_graph(graph, ax, ay);
  if (!a || is_in_graph(graph, bx, by))
    return; // it's an edge, it must be linked to something
  add_point(graph, bx, by);
  Point *b = get_vertex(graph, graph->nb_vertices);
  // edge creation
  Edge *e = malloc(sizeof(Edge));
  e->a = a;
  e->b = b->name;
  e->next = 0;
  // TODO insert edge
}

short vertex2mmd(const Point *point, FILE *file, short known) {
  if (known)
    fprintf(file, "%d", point->name);
  else
    fprintf(file, "%d(%d,%d)", point->name, point->x, point->y);
  return 1;
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
    // fetching points
    Point *pa = get_vertex(graph, e->a);
    Point *pb = get_vertex(graph, e->b);
    // writing the line
    fputc('\t', file);
    known[pa->name] = vertex2mmd(pa, file, known[pa->name]);
    fprintf(file, " -> ");
    known[pb->name] = vertex2mmd(pb, file, known[pb->name]);
    fputc('\n', file); // next one
  }
}

int is_in_graph(const Graph *graph, unsigned int x, unsigned int y) {
  return 0;
}
