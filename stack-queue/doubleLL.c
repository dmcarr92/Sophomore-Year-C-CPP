#include "doubleLL.h"

dlinklist* createDLinklist(){

  dlinklist* dll = malloc(sizeof(dlinklist));
  dll->head = NULL;
  dll->tail = NULL;
  return dll;
}

dnode* createDNode(data* d){

  dnode* dn = malloc(sizeof(dnode));
  dn->next = NULL;
  dn->prev = NULL;
  dn->d = d;
  return dn;
}

int doubleLLSize(dlinklist* dll){

  int count = 0;
  dnode* tmp;
  for(tmp = dll->head; tmp!=NULL; tmp=tmp->next){

    count++;
  }
  return count;
}

void addMiddle(dlinklist* dll,data* d){

  int size = doubleLLSize(dll);
  dnode* tmp = dll->head;
  int half = size/2;
    
  while(tmp != NULL && half != 1){
        
    tmp = tmp->next;
    half--;
  }
    
  if(tmp == NULL || size == 1){
        
    addBackD(dll,d);
  }
  else{

    dnode* newNode = createDNode(d);
    dnode* prevNode = tmp->prev;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    tmp->prev = newNode;
    newNode->next = tmp;
  }
}

void addFrontD(dlinklist* dll,data* d){

  dnode* newNode = createDNode(d);
  if(dll->head == NULL && dll->tail == NULL){

    dll->head = newNode;
    dll->tail = newNode;
  }
  else{

    newNode->next = dll->head;
    dll->head->prev = newNode;
    dll->head = newNode;
  }
}

void addBackD(dlinklist* dll,data* d){

  dnode* newNode = createDNode(d);
  if(dll->head == NULL && dll->tail == NULL){

    dll->head = newNode;
    dll->tail = newNode;
  }
  else{

    newNode->prev = dll->tail;
    dll->tail->next = newNode;
    dll->tail = newNode;
  }
}

void printForward(dlinklist* dll){

  dnode* tmp;
  for(tmp = dll->head; tmp!= NULL; tmp=tmp->next){
    printData(tmp->d);
  }
  printf("\n");
}

void printBackwards(dlinklist* dll){

  dnode* tmp;
  for(tmp=dll->tail; tmp!= NULL; tmp=tmp->prev){

    printData(tmp->d);
  }
  printf("\n");
}

dnode* getFront(dlinklist* dll){

  return dll->head;
}

void removeFront(dlinklist* dll){

  if(dll->head == NULL && dll->tail == NULL)return;
  if(dll->head == dll->tail){

    freeDNode(dll->head);
    dll->head = NULL;
    dll->tail = NULL;
  }
  else{
      
    dnode* tmp = dll->head;
    dll->head = tmp->next;
    dll->head->prev = NULL;
    freeDNode(tmp);
  }
}

void freeDNode(dnode* dn){

  freeData(dn->d);
  free(dn);
}
