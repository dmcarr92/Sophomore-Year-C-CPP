#include "linklist.h"

linklist* createLinklist(){

  linklist* ll = malloc(sizeof(linklist));
  ll->head = NULL;
  return ll;
}

void printLinklist(linklist* ll){

  int i = 0;
  node* temp = NULL;
  for(temp = ll->head;temp != NULL;temp = temp->next){

    i++;
    printf("Node #%d: ",i);
    printData(temp->dta);
  }
}

node* createNode(data* d){

  node* newNode = malloc(sizeof(node));
  newNode->next = NULL;
  newNode->dta = d;
  return newNode;
}

void lladdFront(linklist* ll,data* d){

  node* newNode = createNode(d);
  newNode->next = ll->head;
  ll->head = newNode;
}

linklist* linklistFromFile(char* fname){

  linklist* ll = createLinklist();
  FILE* fpr = openfileRead(fname);
  while(1){

    data* d = readData(fpr);
    if(d == NULL){

      break;
    }
    lladdFront(ll,d);
  }
  close(fpr);
  return ll;
}

node* searchLinklist(linklist* ll,float v){

  int nodeCount = 0;
  data* tmpD = createData(0,0,0.0);
  node* tmpN = createNode(tmpD);
  for(tmpN = ll->head;tmpN != NULL;tmpN = tmpN->next){

    nodeCount++;
    if(tmpN->dta->f1 == v){

      printf("\n%.3f was located in node #%d\n\n",v,nodeCount);
      return tmpN;
    }
  }
  printf("\nProgram unable to locate %.3f\n\n",v);
  free(tmpN);
  return NULL;
}

void lladdEnd(linklist* ll,data* d){

  node* newNode = createNode(d);
  node* temp = NULL;
  for(temp = ll->head;temp != NULL;temp = temp->next){

    if(temp->next == NULL){

      temp->next = newNode;
      break;
    }
  }
}

void lladdNpos(linklist* ll,data* d,int n){

  int i = 1;
  node* newNode = createNode(d);
  node* temp = ll->head;
  node* prev = NULL;
  for(i;i < n;i++){

    prev = temp;
    temp = prev->next;
  }
  if(i == 1){

    temp->next = ll->head;
    ll->head = temp;
  }
  prev->next = newNode;
  newNode->next = temp;
}

void reverseLinklist(linklist* ll){

  //create a temporary dummy linklist pointer and node pointer
  linklist* tempLL = malloc(sizeof(linklist));
  node* tempN = NULL;
  //set the head of the dummy linklist equal to the head of the
  //input linklist
  tempLL->head = createNode(ll->head->dta);
  //step through the nodes of the input linklist, beginning with 
  //the one right after the head, using the addFront function to
  //create a new node from each node's data and add them to the front
  //of the dummy linklist
  for(tempN = ll->head->next;tempN != NULL;tempN = tempN->next){

    lladdFront(tempLL,tempN->dta);
  }
  //set input linklist pointer equal to the one we just created
  ll->head = tempLL->head;
  free(tempN);
  free(tempLL);
}


























