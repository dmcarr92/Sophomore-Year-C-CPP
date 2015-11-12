#include "linklist.h"

int main(int argc,char* argv[]){

  linklist* ll = linklistFromFile(argv[1]);
  printf("\nNew linklist generated from file '%s'\n",argv[1]);

  node* floatLoc = searchLinklist(ll,3.53);

  printf("**FIRST PRINT**\nno changes made\n\n");
  printLinklist(ll);

  data* d1 = createData(12,29,13.890);
  data* d2 = createData(4,193,15.236);

  lladdEnd(ll,d1);
  lladdNpos(ll,d2,4);

  printf("\n**SECOND PRINT**\ndata nodes added to end of\nlinklist, and position 4\n\n");
  printLinklist(ll);

  reverseLinklist(ll);
  
  printf("\n**THIRD PRINT**\nlinklist reversed\n\n");
  printLinklist(ll);


  return 0;
}
