#include "queue.h"
#include "stack.h"
#include <time.h>

int main(int argc,char* argv[]){

  printf("\nPROGRAM BEGUN\n");

//generating a readable .txt file
  srand(time(NULL));
  FILE* out = fopen(argv[2],"w");
  int i;
  int v1;
  int v2;
  float v3;
  for(i = 0;i < atoi(argv[1]);i++){

    v1 = rand() % 100;
    v2 = rand() % 200;
    v3 = (rand() % 10000)/100.00;
    fprintf(out,"%d %d %f\n",v1,v2,v3);
  }
  fclose(out);

//opening the generated .txt file w/ read privileges
//then reading the data structures into a stack
  FILE* read = fopen(argv[2],"r");
  stack* s = createStack();
  data* d = malloc(sizeof(data));
  while(1){

    d = readData(read);
    if(d == NULL){

      break;
    }
    pushStack(s,d);
  }

//printing the stack
  printf("\nPRINTING STACK\n\n");
  printStack(s);

//creating a queue and pushing the data from the stack to it
  dnode* tempN = frontStack(s);
  queue* q = createQueue();

//remember that to do this we must:
//1. begin a while loop that runs while [emptyStack(s) != 0]
//2. set a temp dnode equal to the head of the stack
//3. create a NEW data structure from the data within this temp dnode
//4. use the pushQueue function with this newly created data struct
//5. pop the front element off of the stack, effectively deleting it
  while(emptyStack(s) != 1){

    tempN = frontStack(s);
    d = createData(tempN->d->i1,tempN->d->i2,tempN->d->f1);
    pushQueue(q,d);
    popStack(s);
  }

//printing the queue
  printf("\nPRINTING QUEUE\n\n");
  printQueue(q);
  if(emptyStack(s) == 1){

    printf("\nSTACK EMPTY\n\n");
  }
  return 0;
}
