#ifndef QUEUE_H_
#define QUEUE_H_

#include "doubleLL.h"

typedef struct{

  dlinklist* qu;
}queue;

//malloc space for queue and initialize vars
queue* createQueue();
//create node and push it on to the queue (add to the end of dlinklist)
void pushQueue(queue* q,data* d);
//remove node from front of queue (remove from front of dlinklist)
void popQueue(queue* q);
//return pointer to node at front of queue
dnode* frontQueue(queue* q);
//return 1 if queue is empty and -1 if queue is not empty
int emptyQueue(queue* q);
//print all elements in queue.  must use push and pop for this
void printQueue(queue* q);

#endif
