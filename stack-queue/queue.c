#include "queue.h"
#include "stack.h"

queue* createQueue(){

  queue* q = malloc(sizeof(queue));
  q->qu = createDLinklist();
  return q;
}

void pushQueue(queue* q,data* d){

  addBackD(q->qu,d);
}

void popQueue(queue* q){

  removeFront(q->qu);
}

dnode* frontQueue(queue* q){

  dnode* temp = q->qu->head;
  return temp;
}

int emptyQueue(queue* q){

  int check = -1;
  if(q->qu->head == NULL && q->qu->tail == NULL){

    check = 1;
  }
  return check;
}

void printQueue(queue* q){

  if(emptyQueue(q) == 1){

    printf("\nThe queue is empty.\n");
    return;
  }
  queue* tempQ = createQueue();
  dnode* tempN = frontQueue(q);
  data* d = createData(tempN->d->i1,tempN->d->i2,tempN->d->f1);
  while(emptyQueue(q) != 1){

    tempN = frontQueue(q);
    d = createData(tempN->d->i1,tempN->d->i2,tempN->d->f1);
    printData(d);
    pushQueue(tempQ,d);
    popQueue(q);
  }
  while(emptyQueue(tempQ) != 1){

    tempN = frontQueue(tempQ);
    d = createData(tempN->d->i1,tempN->d->i2,tempN->d->f1);
    pushQueue(q,d);
    popQueue(tempQ);
  }
  return;
}

  



