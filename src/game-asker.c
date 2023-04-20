#include <stdio.h>
#include <limits.h>
#include "constants.h"
#include "search.h"
#include "game-asker.h"

int player_asker(int player_id, int board[]) {
  int targetPos;
  int x = -1;
  int y = -1;

  while(x<0 || x>2 || y<0 || y>2 || board[targetPos] != PLAYER_N) {
    printf("\nPlayer%d ┌──────────── Row: ", player_id);
    scanf("%d", &x);
    printf("────────┤\n        └───────── Column: ");
    scanf("%d", &y);
    fflush(stdin);
    targetPos = x*3+y;
  }
  return targetPos;
}

int ai_asker(int player_id, int board[]) {
  int best_score = INT_MIN;
  int move = -1;
  int score;
  int aux;

  for (int i = 0; i < BOARD_LEN; i++) {
    if(board[i] == PLAYER_N) {
      board[i] = PLAYER_2;
      score = minimax(board, 0, PLAYER_2);
      board[i] = PLAYER_N;

      if(score > best_score) {
        best_score = score;
        move = i;
      }
      aux = i;
    }
  }
  return (move == -1)? aux : move;
}
