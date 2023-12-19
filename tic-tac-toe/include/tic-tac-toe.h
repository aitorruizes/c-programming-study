#pragma once

void printBoard();
void resetBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char winner);
void askRowAndColumnPositions(int *rowPosition, int *columnPosition);
void handleMove(char moveType[]);
bool hasGameEnded(char winner);
void startGame();

