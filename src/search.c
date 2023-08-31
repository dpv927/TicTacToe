#include <limits.h>
#include "search.h"
#include "game_info.h"
#include "board_info.h"
#include "board.h"
#include "heuristic.h"

int alphabeta(int* board, const int is_maximizing, const int pmaxId, const int pminId, const int depth, const int maxdepth, int alpha, int beta) {

  int eval = heuristic(board, pmaxId); 
  if(eval != EVAL_KEEP || depth == maxdepth) { // Terminal node
    return (eval == MAX_EVAL)? MAX_EVAL - depth :
      ((eval == MIN_EVAL)? MIN_EVAL + depth : NO_EVAL);
  }

  int best_score;

  if(is_maximizing) {
    best_score = INT_MIN;
    
    for (int i = 0; i < BOARD_LEN; i++) {
      if(board[i] == PLAYER_N) {
        board[i] = pmaxId;
        best_score = max(alphabeta(board, 0, pmaxId, pminId, depth+1, maxdepth, alpha, beta), best_score);
        board[i] = PLAYER_N;

        if(best_score > beta){ 
          break; 
        } // Beta Cutoff
        
        alpha = max(alpha, best_score);
      }
    }
  }
  else{
    best_score = INT_MAX;

    for (int i = 0; i < BOARD_LEN; i++) {
      if (board[i] == PLAYER_N) {
        board[i] = pminId;
        best_score = min(alphabeta(board, 1, pmaxId, pminId, depth+1, maxdepth, alpha, beta), best_score);
        board[i] = PLAYER_N;

        if(best_score < alpha){ 
          break;
        } // Alpha Cutoff
        
        beta = min(beta, best_score);
      }
    }
  }
  return best_score;
}
