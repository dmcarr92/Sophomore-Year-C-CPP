#ifndef DOUBLELL_H_
#define DOUBLELL_H_

#include "dataType.h"
#include "readWrite.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct dnodePtr{

  struct dnodePtr* next;
  struct dnodePtr* prev;
  data* d;
}dnode;

typedef struct{

  dnode* head;
  dnode* tail;
}dlinklist;

dlinklist* createDLinklist();
dnode* createDNode(data* d);
void addFrontD(dlinklist* dll,data* d);
void addBackD(dlinklist* dll, data* d);
void removeFront(dlinklist* dll);
void printForward(dlinklist* dll);
void printBackwards(dlinklist* dll);
int doubleLLSize(dlinklist* dll);
void addMiddle(dlinklist* dll, data* d);
dnode* getFront(dlinklist* dll);
void freeDNode(dnode* dn);

#endif
