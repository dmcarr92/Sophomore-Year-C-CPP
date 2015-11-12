#include "dataType.h"

data* createData(int v1,int v2,float v3)
{
  data* newData = malloc(sizeof(data));
  newData->i1 = v1;
  newData->i2 = v2;
  newData->f1 = v3;

  return newData;
}

void printData(data* d)
{
  printf("\n\n%d\n\n%d\n\n%.2f\n\n",d->i1,d->i2,d->f1);

}

void freeData(data* d)
{
  free(d);

}
