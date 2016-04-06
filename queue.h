#ifndef QUEUE_H
#define QUEUE_H

#include "graph.h"

#ifdef __cplusplus
extern "C" {
#endif

    
//-------------------------------------------------------------------------

    struct s_queueElement {
        vertex *v;
        treeNode *parent;
    };
    
    typedef struct s_queueElement queueElement;

    struct s_queue {
        int size;
        queueElement **els;
        int first;
        int last;
        int lastAdded;
    };

    typedef struct s_queue queue;

    queue * createQueue(int size);
    int queueIsFull(queue *q);
    int queueIsEmpty(queue *q);    
    queueElement * createQueueElement(vertex *v, treeNode *parent);
    int enqueue(queue *q, queueElement *e);
    queueElement * dequeue(queue *q);
    queueElement * front(queue *q);
    
#ifdef __cplusplus
}
#endif

#endif /* QUEUE_H */

