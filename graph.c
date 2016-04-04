#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

vertex * createVertex(int key) {
    vertex *r = (vertex *) malloc(sizeof (vertex));
    if (r) {
        r->key = key;
        r->status = NOT_VISITED;
    }
    return r;
}

edge * createEdge(vertex *v1, vertex *v2) {
    edge *r = (edge *) malloc(sizeof (edge));
    if (r) {
        r->v1 = v1;
        r->v2 = v2;
        r->type = UNSET;
    }
    return r;
}

graph * createGraph(int vertexListSize, int edgeListSize) {
    graph *r = (graph *) malloc(sizeof (graph));
    if (r) {
        r->vertices = (vertex **) malloc(vertexListSize * sizeof (vertex *));
        if (r->vertices) {
            r->vertexListSize = vertexListSize;
            r->numVertices = 0;

            r->edges = (edge **) malloc(edgeListSize * sizeof (edge *));
            if (r->edges) {
                r->edgeListSize = edgeListSize;
                r->numEdges = 0;
            } else {
                fprintf(stderr, "No memory for edge list allocation");
                free(r->vertices);
                free(r);
                r = NULL;
            }
        } else {
            fprintf(stderr, "No memory for vertex list allocation");
            free(r);
            r = NULL;
        }
    }
    return r;
}

int addVertex(graph *g, vertex *v) {
    int r = 0;
    if (g->numVertices < g->vertexListSize) {
        g->vertices[g->numVertices++] = v;
    } else {
        vertex **temp = (vertex **)realloc(g->vertices, 2 * g->vertexListSize * sizeof (vertex *));
        if (temp) {
            g->vertices = temp;
            g->vertexListSize *= 2;
            addVertex(g, v);
        } else {
            fprintf(stderr, "Unable to allocate memory for new vertex");
            r = -1;
        }
    }
    return r;
}

int addEdge(graph *g, edge *e) {
    int r = 0;
    if (g->numEdges < g->edgeListSize) {
        g->edges[g->numEdges++] = e;
    } else {
        edge **temp = (edge **)realloc(g->edges, 2 * g->edgeListSize * sizeof (edge *));
        if (temp) {
            g->edges = temp;
            g->edgeListSize *= 2;
            addEdge(g, e);
        } else {
            fprintf(stderr, "Unable to allocate memory for new edge");
            r = -1;
        }
    }
    return r;
}

int numVertices(graph *g) {
    return g->numVertices;
}

int numEdges(graph *g) {
    return g->numEdges;
}

vertex ** vertices(graph *g) {
    return g->vertices;
}

edge ** edges(graph* g) {
    return g->edges;
}

vertex * opposite(edge *e, vertex *v) {
    vertex *r = NULL;
    if (e->v1 == v) {
        r = e->v2;
    } else if (e->v2 == v) {
        r = e->v1;
    }
    return r;
}

vertex ** adjacentVertices(graph *g, vertex *v) {
    vertex **r = (vertex **)malloc((g->numVertices+1) * sizeof (vertex *));
    if (r) {
        vertex *temp = NULL;
        int i = 0, j = 0;
        for (i = 0; i < g->numEdges; i++) {
            if (temp = opposite(g->edges[i], v)) {
                r[j++] = temp;
            }
        }
        // NULL terminated list
        r[j] = NULL;
    }
    return r;
}

edge ** incidentEdges(graph *g, vertex *v) {
    edge **r = malloc((g->numEdges+1) * sizeof (edge *));
    if (r) {
        edge *temp = NULL;
        int i = 0, j = 0;
        for (i = 0; i < g->numEdges; i++) {
            if (opposite(g->edges[i], v)) {
                r[j++] = g->edges[i];
            }
        }
        // NULL terminated list
        r[j] = NULL;
    }
    return r;
}