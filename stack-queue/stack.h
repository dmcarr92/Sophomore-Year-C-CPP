#ifndef STACK_H_
#define STACK_H_

#include "doubleLL.h"

typedef struct{

  dlinklist* st;
}stack;

//create space for stack and initialize vars
stack* createStack();
//push data onto the stack (addFront of dlinklist)
void pushStack(stack* s,data* d);
//pop node off the stack, or remove from front of the dlinklist
void popStack(stack* s);
//return pointer to node at front of stack
dnode* frontStack(stack* s);
//return 1 is stack is empty and -1 is stack is not empty
int emptyStack(stack* s);
//print element on stack.  must use push and pop for this.
void printStack(stack* s);

#endif
