#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/memory-allocation.h"

#define BUFFER_SIZE 4096

int getStringsQuantity()
{
  int stringsQuantity;

  printf("Enter number of strings: ");
  scanf("%d", &stringsQuantity);

  return stringsQuantity;
}

char** allocateMemory(int stringsQuantity)
{
  char **array = malloc(sizeof(char *) * stringsQuantity);

  return array;
}

void clearInputBuffer()
{
  while (getchar() != '\n');
}

void handleAllocateString(int stringsQuantity, char **stringsArray)
{	
  char buffer[BUFFER_SIZE];
  int stringLength = 0;
  
  for (int i = 0; i < stringsQuantity; i++)
  {
    printf("Enter string (%d): ", i + 1);
    fgets(buffer, BUFFER_SIZE, stdin);
    stringLength = strlen(buffer);
    buffer[stringLength - 1] = '\0';
    stringsArray[i] = malloc(sizeof(char) * stringLength);
    strcpy(stringsArray[i], buffer);
  }
}

void printStringsArray(int stringsQuantity, char **stringsArray)
{
  printf("Resulting dynamic allocated array of strings:\n");

  for (int i = 0; i < stringsQuantity; i++)
  {
    if (i == 0)
    {
      printf("['%s', ", stringsArray[i]);
    }
    else if (i == (stringsQuantity - 1))
    {
      printf("'%s']", stringsArray[i]);
    }
    else
    {
      printf("'%s', ", stringsArray[i]);
    }
  }
}

