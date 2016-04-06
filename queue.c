

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

    queue * createQueue(int size) {
        queue *q = NULL;
        q = (queue *) malloc(sizeof (queue));
        if (q) {
            q->els = (queueElement **) malloc(size * sizeof (queueElement *));
            if (q->els) {
                q->size = size;
                q->first = 0;
                q->last = -1;
                q->lastAdded = 0;
            } else {
                free(q);
                q = NULL;
            }
        }
        return q;
    }

    int queueIsFull(queue *q) {
        return ((q->last + 1) % q->size == q->first) && q->lastAdded;
    }

    int queueIsEmpty(queue *q) {
        return ((q->last + 1) % q->size == q->first) && !(q->lastAdded);
    }
    
    queueElement * createQueueElement(vertex *v, treeNode *parent) {
        queueElement *r = (queueElement *)malloc(sizeof(queueElement));
        if(r) {
            r->v = v;
            r->parent = parent;
        }
        return r;
    }

    int enqueue(queue *q, queueElement *e) {
        int r = 0;
        if (!queueIsFull(q)) {
            q->last = (q->last + 1) % q->size;
            q->els[q->last] = e;
            q->lastAdded = 1;
            r = 1;
        }
        return r;
    }

    queueElement * dequeue(queue *q) {
        queueElement *r = NULL;
        if (!queueIsEmpty(q)) {
            r = q->els[q->first];
            q->first = (q->first + 1) % q->size;
            q->lastAdded = 0;
        }
        return r;
    }

    queueElement * front(queue *q) {
        queueElement *r = NULL;
        if (!queueIsEmpty(q)) {
            r = q->els[q->first];
        }
        return r;
    }
    
