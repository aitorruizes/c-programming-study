#include "../include/number-pattern.h"

int main()
{
  int numberPattern = getNumberFromInput();
  int patternSize = calculatePatternSize(numberPattern);

  handlePrintPattern(numberPattern, patternSize);
  
  return 0;
}

