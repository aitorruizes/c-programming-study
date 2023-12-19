#pragma once

int getNumberFromInput();
int calculatePatternSize(int number);
int calculateVerticalDistance(int rowIndex, int patternSize);
int calculateHorizontalDistance(int columnIndex, int patternSize);
int calculateCurrentPositionValue(int verticalDistance, int horizontalDistance);
void handlePrintPattern(int numberPattern, int patternSize);

