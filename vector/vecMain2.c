#include "vector.h"

int main(int argc,char* argv[]){

  vector* vec = createVector();

  writeVector(vec,argv[1]);

  printVector(vec);

  removeFront(vec);
  removeFront(vec);

  removeNpos(vec,9);

  searchRemove(vec,5);
  searchRemove(vec,2);

  printVector(vec);

  float vectorAvg = calcAverage(vec);

  return 0;
}

  

  
