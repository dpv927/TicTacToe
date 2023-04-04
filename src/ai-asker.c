#include <limits.h>
#include "constants.h"
#include "search.h"
#include "ai-asker.h"

int ai_asker(int player_id, int* board) {
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
