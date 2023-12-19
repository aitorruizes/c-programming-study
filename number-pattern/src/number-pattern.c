#include <stdio.h>
#include "../include/number-pattern.h"

int getNumberFromInput()
{
	int number;

	printf("Enter a number to create a pattern: ");
	scanf("%d", &number);

	return number;
}

int calculatePatternSize(int number)
{
	return 2 * number - 1;
}

int calculateVerticalDistance(int rowIndex, int patternSize)
{
	int verticalDistance;

	if (rowIndex < (patternSize - rowIndex))
	{
		verticalDistance = rowIndex;
	}
	else
	{
		verticalDistance = patternSize - rowIndex - 1;
	}

	return verticalDistance;
}

int calculateHorizontalDistance(int columnIndex, int patternSize)
{
	int horizontalDistance;

	if (columnIndex < (patternSize - columnIndex))
	{
		horizontalDistance = columnIndex;
	}
	else
	{
		horizontalDistance = patternSize - columnIndex - 1;
	}

	return horizontalDistance;
}

int calculateCurrentPositionValue(int verticalDistance, int horizontalDistance)
{
	if (verticalDistance > horizontalDistance)
	{
		return horizontalDistance;
	}
	else
	{
		return verticalDistance;
	}
}

void handlePrintPattern(int numberPattern, int patternSize)
{
	for (int i = 0; i < patternSize; i++)
	{
		for (int j = 0; j < patternSize; j++)
		{
			int verticalDistance = calculateVerticalDistance(i, patternSize);
			int horizontalDistance = calculateHorizontalDistance(j, patternSize);
			int value = (horizontalDistance < verticalDistance) ? horizontalDistance : verticalDistance;

			value = numberPattern - value;

			printf("%d ", value);
		}

		printf("\n");
	}
}
