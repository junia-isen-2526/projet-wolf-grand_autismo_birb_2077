#ifndef WOLF_GRAPH__H
#define WOLF_GRAPH__H

typedef struct _st_graph Graph;

Graph *mk_graph();
void del_graph(const Graph *graph);

void add_point(Graph *graph, int x, int y);
char *graph2string(const Graph *graph);
short is_in_graph(const Graph *graph, int x, int y);

#endif // WOLF_GRAPH__H
