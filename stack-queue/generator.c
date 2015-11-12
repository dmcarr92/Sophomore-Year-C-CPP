#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char* argv[]){

  srand(time(NULL));

  FILE* out = fopen(argv[2],"w");
  
  int i;
  for(i =0; i< atoi(argv[1]); i++){

    int v1 = rand() % 100;
    int v2 = rand() % 200;
    float v3 = (rand() % 10000)/100.00;
    fprintf(out,"%d %d %f\n",v1,v2,v3);
  }

  return 0;
}
