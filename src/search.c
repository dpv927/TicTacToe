#include <limits.h>
#include <stdint.h>
#include "search.h"
#include "heuristic.h"
#include "bits.h"
#include "game.h"

int alphabeta(const int is_maximizing, uint16_t pmax, uint16_t pmin, const int depth, const int maxdepth, int alpha, int beta){

  int eval = heuristic(pmax, pmin); 
  if(eval != EVAL_KEEP || depth == maxdepth) { // Terminal node
    return (eval == MAX_EVAL)? MAX_EVAL - depth :
      ((eval == MIN_EVAL)? MIN_EVAL + depth : NO_EVAL);
  }

  int best_score;
  uint16_t state = pmax|pmin;

  if(is_maximizing) {
    best_score = INT_MIN;
    
    for (int i = 0; i < 9; i++) {   
      if(!getBit(state, i)) {
        setbit(pmax, i);
        best_score = max(alphabeta(0, pmax, pmin, depth+1, maxdepth, alpha, beta), best_score);
        setZeroBit(pmax, i);

        if(best_score > beta){ 
          break; 
        } // Beta Cutoff       
        alpha = max(alpha, best_score);
      }
    }
  }
  else{
    best_score = INT_MAX;

    for (int i = 0; i < 9; i++) {
      if (!getBit(state, i)) {
        setbit(pmin, i);
        best_score = min(alphabeta(1, pmax, pmin, depth+1, maxdepth, alpha, beta), best_score);
        setZeroBit(pmin, i);

        if(best_score < alpha){ 
          break;
        } // Alpha Cutoff
        beta = min(beta, best_score);
      }
    }
  }
  return best_score;
}
