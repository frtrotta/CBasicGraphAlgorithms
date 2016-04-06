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
    addEdge(g, createEdge(a, b, "ab"));
    addEdge(g, createEdge(b, c, "bc"));
    addEdge(g, createEdge(a, c, "ac"));
    addEdge(g, createEdge(b, d, "bd"));
    addEdge(g, createEdge(d, c, "dc"));
    addEdge(g, createEdge(d, e, "de"));

    vertex *root = a;
    
    unVisitGraph(g);
    treeNode *DFSroot = DFS(g, root);
    
    unVisitGraph(g);
    treeNode *BFSroot = BFS(g, root);

    printf("\nDFS spanning tree:\t");
    TreeDFSPrint(DFSroot, 0);
    printf("\nBFS spanning tree:\t");    
    TreeDFSPrint(BFSroot, 0);

    return (EXIT_SUCCESS);
}

