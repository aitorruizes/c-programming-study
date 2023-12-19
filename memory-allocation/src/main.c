#include "../include/memory-allocation.h"

int main()
{	
  int stringsQuantity = getStringsQuantity();
  char **stringsArray = allocateMemory(stringsQuantity);
  
  clearInputBuffer();
  handleAllocateString(stringsQuantity, stringsArray);
  printStringsArray(stringsQuantity, stringsArray);

  return 0;
}
