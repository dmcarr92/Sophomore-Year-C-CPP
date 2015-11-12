#include "dataType.h"

int main(int argc,char* argv)
{
  data* newData = createData(6,9,3.1);
  printData(newData);
  freeData(newData);

  return 0;
}
