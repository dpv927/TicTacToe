#include <stdio.h>
#include "constants.h"

int readCoordinates(int id) {
  int alias = (id == PLAYER_1)? 1 : 2;
  int x = -1;
  int y = -1;

  while(x<0 || x>2 || y<0 || y>2) {
    printf("\nPlayer%d ┌──────────── Row: ", alias);
    scanf("%d", &x);
    printf("────────┤\n        └───────── Column: ");
    scanf("%d", &y);
    fflush(stdin);
  }
  return x*3+y;
}

int player_asker(int player_id, int* board) {
  int targetPos = readCoordinates(player_id);
  
  while (board[targetPos] != PLAYER_N) {
    targetPos = readCoordinates(player_id);
  }
  return targetPos;
}