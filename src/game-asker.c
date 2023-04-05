#include <stdio.h>
#include <limits.h>
#include "constants.h"
#include "search.h"
#include "game-asker.h"

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

int player_asker(int player_id, int board[]) {
  int targetPos = readCoordinates(player_id);
  
  while (board[targetPos] != PLAYER_N) {
    targetPos = readCoordinates(player_id);
  }
  return targetPos;
}

int ai_asker(int player_id, int board[]) {
  int best_score = INT_MIN;
  int move;
  int score;
  player_id = 0;
  player_id++;

  for (int i = 0; i < BOARD_LEN; i++) {
    if(board[i] == PLAYER_N) {
      board[i] = PLAYER_2;
      score = minimax(board, 0);
      board[i] = PLAYER_N;

      if(score > best_score) {
        best_score = score;
        move = i;
      }
    }
  }
  return move;
}