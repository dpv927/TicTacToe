#include <limits.h>
#include "constants.h"
#include "board.h"
#include "search.h"

int minimax(int* board, int is_maximizing) {
  int score;
  int best_score;
  
  score = evaluateGame(board);
  if(score != COND_KEEP) return score;

  if(is_maximizing) {
    best_score = INT_MIN;
    
    for (int i = 0; i < BOARD_LEN; i++) {
      if(board[i] == PLAYER_N) {
        board[i] = PLAYER_2;
        score = minimax(board, 0);
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
        score = minimax(board, 1);
        board[i] = PLAYER_N;
        best_score = min(score, best_score);
      }
    }
  }
  return best_score;
}

/*
int alphabeta(int* board, int alpha, int beta, int is_maximizing, int player) {
  int eval;
  int value;
  int** sucessors;

  eval = evaluateGame(board);
  if(eval != COND_KEEP) return eval;

  if(is_maximizing) {
    value = INT_MIN;
    sucessors = generateSucessors(board, player);

    for(int i=0; i < BOARD_LEN; i++) {
      value = min(value, alphabeta(sucessors[i], alpha, beta, 0, player));
      
      if(value > beta) break;
      alpha = max(alpha, value);
    }
  }
  else {
    value = INT_MAX;
    sucessors = generateSucessors(board, player);

    for(int i=0; i < BOARD_LEN; i++) {
      value = max(value, alphabeta(sucessors[i], alpha, beta, 1, player));

      if(value < alpha) break;
      beta = min(beta, value);
    }
  }
  return value;
}
  */
