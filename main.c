#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char** argv) {
    graph *g = createGraph(8, 8);
    
    vertex *a = createVertex('A');
    vertex *b = createVertex('B');
    vertex *c = createVertex('C');    
    vertex *d = createVertex('D');
    vertex *e = createVertex('E');
    addVertex(g, a);
    addVertex(g, b);
    addVertex(g, c);
    addVertex(g, d);
    addVertex(g, e);
    addEdge(g, createEdge(a, b));
    addEdge(g, createEdge(b, c));
    addEdge(g, createEdge(a, c));
    addEdge(g, createEdge(b, d));
    addEdge(g, createEdge(d, c));
    addEdge(g, createEdge(d, e));
    
    vertex *root = a;
    unVisitGraph(g);
    
    treeNode *DFSroot = DFS(g, root);
    
    printf("\n");
    
    DFStree(DFSroot);
    
    return (EXIT_SUCCESS);
}

