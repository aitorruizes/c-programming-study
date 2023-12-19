#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "../include/tic-tac-toe.h"

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
const char PLAYER_CHARACTER = 'X';
const char COMPUTER_CHARACTER = 'O';

void printBoard()
{
  printf("+-----------+\n");
  printf("| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
  printf("|---|---|---|\n");
  printf("| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
  printf("|---|---|---|\n");
  printf("| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
  printf("+-----------+\n");
}

void resetBoard()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      board[i][j] = ' ';
    }
  }
}

int checkFreeSpaces()
{
  int freeSpaces = 9;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] != ' ')
      {
        freeSpaces--;
      }
    }
  }

  return freeSpaces;
}

void playerMove()
{
  int rowPosition;
  int columnPosition;

  bool hasMoveToValidPosition = false;

  do
  {
    askRowAndColumnPositions(&rowPosition, &columnPosition);

    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if (board[rowPosition][columnPosition] != ' ')
        {
          printf("You can not move to an occupied position.\n");
          return;
        }
        else
        {
          board[rowPosition][columnPosition] = 'X';
          hasMoveToValidPosition = true;
          return;
        }
      }
    }
  } while (!hasMoveToValidPosition);
}

void computerMove()
{
  srand(time(0));

  int rowPosition;
  int columnPosition;

  if (checkFreeSpaces() > 0)
  {
    do
    {
      rowPosition = rand() % 3;
      columnPosition = rand() % 3;
    } while (board[rowPosition][columnPosition] != ' ');

    board[rowPosition][columnPosition] = COMPUTER_CHARACTER;
  }
  else
  {
    printWinner(' ');
  }
}

char checkWinner()
{
  for (int i = 0; i < 3; i++)
  {
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
    {
      return board[i][0];
    }
  }

  for (int i = 0; i < 3; i++)
  {
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
    {
      return board[0][i];
    }
  }

  if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
  {
    return board[0][0];
  }

  if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
  {
    return board[0][2];
  }

  return ' ';
}

void printWinner(char winner)
{
  if (winner == PLAYER_CHARACTER)
  {
    printf("The player has won!\n");
  }
  else if (winner == COMPUTER_CHARACTER)
  {
    printf("The computer has won!\n");
  }
  else
  {
    printf("It's a tie!\n");
  }
}

void askRowAndColumnPositions(int *rowPosition, int *columnPosition)
{
  printf("Select a row position (1-3): ");
  scanf("%d", rowPosition);

  *(rowPosition) -= 1;

  printf("Select a column position (1-3): ");
  scanf("%d", columnPosition);

  *(columnPosition) -= 1;
}

void handleMove(char moveType[])
{
  if (strcmp(moveType, "player") == 0)
  {
    playerMove();
  }
  else if (strcmp(moveType, "computer") == 0)
  {
    computerMove();
  }
}

bool hasGameEnded(char winner)
{
  if (winner != ' ')
  {
    return true;
  }

  if (checkFreeSpaces() == 0)
  {
    return true;
  }

  return false;
}

void startGame()
{
  resetBoard();

  do
  {
    printBoard();

    handleMove("player");

    if (hasGameEnded(checkWinner()))
    {
      break;
    }

    handleMove("computer");

    if (hasGameEnded(checkWinner()))
    {
      break;
    }
  } while (checkWinner() == ' ' && checkFreeSpaces() != 0);

  printBoard();
  printWinner(checkWinner());
}
