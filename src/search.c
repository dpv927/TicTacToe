#include <limits.h>
#include "search.h"
#include "board_info.h"
#include "player.h"
#include "heuristic.h"

int minimax(int* board, int is_maximizing, int pmaxId, int pminId) {
  int score;
  int best_score;

  score = heuristic(board, pmaxId);
  if(score == MAX_EVAL || score == MIN_EVAL || score == NO_EVAL)
    return score;

  if(is_maximizing) {
    best_score = INT_MIN;
    
    for (int i = 0; i < BOARD_LEN; i++) {
      if(board[i] == PLAYER_N) {
        board[i] = pmaxId;
        score = minimax(board, 0, pmaxId, pminId);
        board[i] = PLAYER_N;
        best_score = max(score, best_score);
      }
    }
  }
  else{
    best_score = INT_MAX;

    for (int i = 0; i < BOARD_LEN; i++) {
      if (board[i] == PLAYER_N) {
        board[i] = pminId;
        score = minimax(board, 1, pmaxId, pminId);
        board[i] = PLAYER_N;
        best_score = min(score, best_score);
      }
    }
  }
  return best_score;
}
