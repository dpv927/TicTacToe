#include <stdio.h>
#include <limits.h>
#include "game_asker.h"
#include "player.h"
#include "search.h"
#include "board_info.h"

int player_asker(int player_id, int* board) {
  int targetPos;
  int x = -1;
  int y = -1;

  while(x<0 || x>2 || y<0 || y>2 || board[targetPos] != PLAYER_N) {
    printf("\nPlayer%d ┌──────────── Row: ", player_id);
    int errX = scanf("%d", &x);
    printf("────────┤\n        └───────── Column: ");
    int errY = scanf("%d", &y);
    fflush(stdin);

    if(errX != 1 || errY !=1) { x = y = -1; }
    targetPos = x*3+y;
  }
  return targetPos;
}

int ai_asker(int player_id, int* board) {
  int pmax = player_id;
  int pmin = (pmax == PLAYER_2)? PLAYER_1 : PLAYER_2; 
  int best_score = INT_MIN;
  int move = -1;
  int score;
  int aux;

  for (int i = 0; i < BOARD_LEN; i++) {
    if(board[i] == PLAYER_N) {
      board[i] = pmax;
      score = minimax(board, 0, pmax, pmin);
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