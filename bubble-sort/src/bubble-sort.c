#include <stdio.h>
#include <stdbool.h>
#include "../include/bubble-sort.h"

void printConsoleHeader()
{
  printf("+-----------------------+\n");
  printf("| BUBBLE SORT ALGORITHM |\n");
  printf("+-----------------------|\n");
}

void printFormattedArray(const char message[], int array[], const int arraySize)
{
  printf("%s\n", message);

  for (int i = 0; i < arraySize; i++)
  {
    if (i == 0)
    {
      printf("-> [");
    }

    if (i == (arraySize - 1))
    {
      printf("%d]\n", array[i]);
    }
    else
    {
      printf("%d, ", array[i]);
    }
  }
}

void bubbleSort(int array[], const int arraySize)
{
  bool hasSwapped;

  do
  {
    hasSwapped = false;
    
    for (int i = 0; i < arraySize; i++)
    {
      if ((i + 1) > (arraySize - 1))
      {
        break;
      }

      if (array[i] > array[i + 1])
      {
        int temp = array[i];

        array[i] = array[i + 1];
        array[i + 1] = temp;

        hasSwapped = true;
      }
    }

  } while (hasSwapped);
}
