#include <limits.h>
#include "constants.h"
#include "board.h"
#include "search.h"

int minimax(int board[], int is_maximizing, int player_id) {
  int score;
  int best_score;

  score = evaluateGame(board, player_id);
  if(score != COND_KEEP) return score;

  if(is_maximizing) {
    best_score = INT_MIN;
    
    for (int i = 0; i < BOARD_LEN; i++) {
      if(board[i] == PLAYER_N) {
        board[i] = PLAYER_2;
        score = minimax(board, 0, player_id);
        board[i] = PLAYER_N;
        best_score = max(score, best_score);
      }
    }
  }
  else{
    best_score = INT_MAX;

    for (int i = 0; i < BOARD_LEN; i++) {
      if (board[i] == PLAYER_N) {
        board[i] = PLAYER_1;
        score = minimax(board, 1, player_id);
        board[i] = PLAYER_N;
        best_score = min(score, best_score);
      }
    }
  }
  return best_score;
}
