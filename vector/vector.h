#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include "dataType.h"
#include "readWrite.h"

typedef struct{

  int size;
  data** array;
}vector;

vector* createVector();

void writeVector(vector* v,char* fname);

void addBegin(vector* v,data* d);

void addEnd(vector* v,data* d);

void printVector(vector* v);

void freeVector(vector* v);

int search(vector* v,int v1);

void addNpos(vector* v,data* d,int n);

#endif
