#ifndef LINKLIST_H_
#define LINKLIST_H_

#include "dataType.h"
#include "readWrite.h"

typedef struct nodePtr{

  struct nodePtr* next;
  data* dta;
}node;

typedef struct{

  node* head;
}linklist;

linklist* createLinklist();

void printLinklist(linklist* ll);

node* createNode(data* d);

void lladdFront(linklist* ll,data* d);

linklist* linklistFromFile(char* fname);

node* searchLinklist(linklist* ll,float v);

void lladdEnd(linklist* ll,data* d);

void lladdNpos(linklist* ll,data* d,int n);

void reverseLinklist(linklist* ll);

#endif
