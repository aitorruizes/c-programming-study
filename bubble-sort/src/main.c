#include "../include/bubble-sort.h"

int main()
{
	int array[] = {2, 7, 3, 9, 1, 5, 4, 8, 6};
	const int arraySize = sizeof(array) / sizeof(int);

	printConsoleHeader();	
	printFormattedArray("Before sorting: ", array, arraySize);
	bubbleSort(array, arraySize);
	printFormattedArray("After sorting: ", array, arraySize);

	return 0;
}
