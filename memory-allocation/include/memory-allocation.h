#pragma once

int getStringsQuantity();
char** allocateMemory(int stringsQuantity);
void clearInputBuffer();
void handleAllocateString(int stringsQuantity, char **stringsArray);
void printStringsArray(int stringsQuantity, char **stringsArray);