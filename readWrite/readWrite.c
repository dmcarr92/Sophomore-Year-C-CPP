#include "readWrite.h"

FILE* openfileRead(char* fname){

  FILE* fpr = fopen(fname,"r");

  if(fpr == NULL){

    printf("\nCould not open file: %s\n\n",fname);
    exit(0);
  }

  return fpr;
}

FILE* openfileWrite(char* fname){

  FILE* fpw = fopen(fname,"w");

  if(fpw == NULL){

    printf("\nCould not open file: %s\n\n",fname);
    exit(0);
  }

  return fpw;
}

/*data* readData(FILE* fp){

  int check = 0;
  int v1;
  int v2;
  float v3;
  check = fscanf(fp,"%d %d %f",&v1,&v2,&v3);
  if(check == -1){
    
    return NULL;
  }
  else{

    data* d = createData(v1,v2,v3);
    return d;
  }
}

void writeData(FILE* out,data* d) {

  fprintf(out,"%d %d %.2f\n",d->i1,d->i2,d->f1);
}*/
