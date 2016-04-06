#ifndef GRAPH_H
#define GRAPH_H

#ifdef __cplusplus
extern "C" {
#endif

    enum v_status {
        NOT_VISITED,
        VISITED
    };

    struct s_vertex {
        char key;
        enum v_status status;
    };

    typedef struct s_vertex vertex;

    enum e_type {
        UNSET,
        DISCOVERY,
        BACK,
        CROSS
    };

    struct s_edge {
        vertex *v1;
        vertex *v2;
        enum e_type type;
    };

    typedef struct s_edge edge;

    struct s_graph {
        int numVertices;
        int numEdges;
        int vertexListSize;
        int edgeListSize;
        vertex **vertices;
        edge **edges;
    };

    typedef struct s_graph graph;

    vertex * createVertex(char key);
    edge * createEdge(vertex *v1, vertex *v2);
    graph * createGraph(int vertexListSize, int edgeListSize);

    int addVertex(graph *g, vertex *v);
    int addEdge(graph *g, edge *e);
    int numVertices(graph *g);
    int numEdges(graph *g);

    vertex ** vertices(graph *g);
    edge ** edges(graph* g);

    vertex * opposite(edge *e, vertex *v);

    vertex ** adjacentVertices(graph *g, vertex *v);

    edge ** incidentEdges(graph *g, vertex *v);

    void unVisitGraph(graph *g);

    // -----------------------------------------

    struct s_treeNode {
        char key;
        struct s_treeNode **children;
        int childrenListSize;
        int childrenNum;
    };

    typedef struct s_treeNode treeNode;

    treeNode * createNode(char key, int childrenListSize);
    int addChildren(treeNode *n, treeNode *child);

    //---------------------------------------------------------------

    treeNode * DFS(graph *g, vertex *v);
    void DFStree(treeNode *n);

#ifdef __cplusplus
}
#endif

#endif /* GRAPH_H */

