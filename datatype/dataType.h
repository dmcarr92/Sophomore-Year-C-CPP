#ifndef DATATYPE_H_
#define DATATYPE_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  int i1;
  int i2;
  float f1;
}data;

data* createData(int v1,int v2,float v3);
void printData(data* d);
void freeData(data* d);

#endif
