#include "vector.h"

int main(int argc,char* argv[]){

  vector* vec = createVector();
  printf("\nnew vector-pointer generated\n\n");

  writeVector(vec,argv[1]);

  printVector(vec);

  int searchResult = search(vec,10);
  printf("%d\n\n",searchResult);

  data* newData1 = createData(51,44,19.290122);
  addBegin(vec,newData1);
  printf("new data added to beginning\n\n");

  data* newData2 = createData(10,59,82.430034);
  addNpos(vec,newData2,6);
  printf("new data added to position 6\n\n");

  searchResult = search(vec,10);
  printf("%d\n\n",searchResult);

  printVector(vec);

  freeVector(vec);
  printf("vector freed\n");

  return 0;
}
