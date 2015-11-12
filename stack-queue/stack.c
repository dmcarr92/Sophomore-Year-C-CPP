#include "stack.h"
#include "queue.h"

stack* createStack(){

  stack* s = malloc(sizeof(stack));
  s->st = createDLinklist();
  return s;
}

void pushStack(stack* s,data* d){

  addFrontD(s->st,d);
}

void popStack(stack* s){

  removeFront(s->st);
}

dnode* frontStack(stack* s){

  dnode* temp = s->st->head;
  return temp;
}

int emptyStack(stack* s){

  int check = -1;
  if(s->st->head == NULL && s->st->tail == NULL){

    check = 1;
  }
  return check;
}

void printStack(stack* s){

  if(emptyStack(s) == 1){

    printf("\nThe stack is empty.\n");
    return;
  }
  stack* tempS = createStack();
  dnode* tempN = frontStack(s);
  data* d = createData(tempN->d->i1,tempN->d->i2,tempN->d->f1);
  while(emptyStack(s) != 1){

    tempN = frontStack(s);
    printData(tempN->d);
    d = createData(tempN->d->i1,tempN->d->i2,tempN->d->f1);
    pushStack(tempS,d);
    popStack(s);
  }
  while(emptyStack(tempS) != 1){

    tempN = frontStack(tempS);
    d = createData(tempN->d->i1,tempN->d->i2,tempN->d->f1);
    pushStack(s,d);
    popStack(tempS);
  }
  return;
}
  
  
    


