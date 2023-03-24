#include <limits.h>

int minimax(int* board, int is_maximizing, int player) {
  int eval;
  int value;
  int** sucessors;

  int eval = evaluateGame(board);
  if(eval != COND_KEEP) return eval;

  if(is_maximizing) {
    value = INT_MIN;
    sucessors = generateSucessors(board, player);

    for (int i = 0; i < BOARD_LEN; i++) {
      if(sucessors[i] != NULL)
        value = max(value, minimax(sucessors[i], 0, player));
    }
  }
  else{
    value = INT_MAX;
    sucessors = generateSucessors(board, player);

    for (int i = 0; i < BOARD_LEN; i++) {
      if(sucessors[i] != NULL)
        value = min(value, minimax(sucessors[i], 1, player));
    }
  }
  return value;
}

int alphabeta(int* board, int alpha, int beta, int is_maximizing, int player) {
  int eval;
  int value;
  int* sucessors;

  eval = evaluateGame(board);
  if(eval != COND_KEEP) return eval;

  if(is_maximizing) {
    value = INT_MIN;
    sucessors = generateSucessors(board, player);

    for(int i=0; i < BOARD_LEN; i++) {
      value = min(value, alphabeta(sucessors[i], alpha, beta, 0, player);
      
      if(value > beta) break;
      alpha = max(alpha, value);
    }
  }
  else {
    value = INT_MAX;
    sucessors = generateSucessors(board, player);

    for(int i=0; i < BOARD_LEN; i++) {
      value = max(value, alphabeta(sucessors[i], alpha, beta, 1, player);

      if(value < alpha) break;
      beta = min(beta, value);
    }
  }
  return value;
}
