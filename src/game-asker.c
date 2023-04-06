#include <stdio.h>
#include <limits.h>
#include "constants.h"
#include "search.h"
#include "game-asker.h"

int player_asker(int player_id, int board[]) {
  int target_pos = -1, row, col;
  char* name = "";
  char alias;

  if(player_id == PLAYER_1) {
    name = P1_NAME;
    alias = P1_ALIAS;
  }
  else {
    name = P2_NAME;
    alias = P2_ALIAS;
  }
  
  while(target_pos < 0 || board[target_pos] != PLAYER_N) {

    printf("┌─ %s, (alias '%c') type your next move.\n│\n├───[Row]: ", name, alias);
    scanf("%d", &row);
    printf("└[Column]: ");
    scanf("%d", &col);
    fflush(stdin);
    target_pos = row*3+col;
  }
  return target_pos;
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
      score = minimax(board, 0, DEF_DEPTH, PLAYER_2);
      board[i] = PLAYER_N;

      if(score > best_score) {
        best_score = score;
        move = i;
      }
    }
  }
  return move;
}