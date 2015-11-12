#include "vector.h"

vector* createVector(){

  vector* newVector = malloc(sizeof(vector));
  newVector->size = 0;
  newVector->array = NULL;
  return newVector;
}

void writeVector(vector* v,char* fname){

  FILE* fp = openfileRead(fname);
  while(1){

    data* d = readData(fp);
    if(d == NULL){

      break;
    }
    addEnd(v,d);
  }
  close(fp);
}

void addBegin(vector* v,data* d){

  v->size++;
  data** temp = malloc(sizeof(data*) * v->size);

  int i = 1;
  for(i;i < v->size;i++){

    temp[i] = v->array[i - 1];
  }
  temp[0] = d;
  free(v->array);
  v->array = temp;
}

void addEnd(vector* v,data* d){

  v->size++;
  data** temp = malloc(sizeof(data*) * v->size);
  int i = 0;
  if(v->size == 1){

    temp[i] = d;
  }
  else{
    for(i;i < v->size;i++){

      temp[i] = v->array[i];
    }
  }
  temp[v->size - 1] = d;
  free(v->array);
  v->array = temp;
}

void printVector(vector* v){

  printf("vector size = %d\n\n",v->size);
  int i = 0;
  for(i;i < v->size;i++){

    printf("vector[%d]: ",i);
    printData(v->array[i]);
  }
}

void freeVector(vector* v){

  int i = 0;
  for(i;i < v->size;i++){

    free(v->array[i]);
  }
  free(v->array);
  free(v);
}

int search(vector* v,int v1){

  printf("searching vector for a %d... -1 signifies a %d was not found,\nany other value represents the data index in which a %d was found: ",v1,v1,v1);
  int i = 0;
  for(i;i < v->size;i++){

    if(v->array[i]->i1 == v1){

      return i;
    }
  }
  return -1;
}

void addNpos(vector* v,data* d,int n){

  v->size++;
  data** temp = malloc(sizeof(data*) * v->size);
  int i = 0;
  if(v->size == 1){

    temp[i] = d;
  }
  else{

    for(i;i < n;i++){

      temp[i] = v->array[i];
    }
  }
  temp[n] = d;
  for(i = n + 1;i < v->size;i++){

    temp[i] = v->array[i - 1];
  }
  free(v->array);
  v->array = temp;
}
