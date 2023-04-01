#include <limits.h>
#include "constants.h"
#include "search.h"
#include "ai-asker.h"

int ai_asker(int player_id, int* board) {
  int bestScore = INT_MIN;
  int move = 0;
  int score = 0;

  for (int i = 0; i < BOARD_LEN; i++) {
    if(board[i] == PLAYER_N) {
      board[i] = player_id;
      score = minimax(board, 1, player_id);
      board[i] = PLAYER_N;

      if(score > bestScore) {
        bestScore = score;
        move = i;
      }
    }
  }
  return move;
}