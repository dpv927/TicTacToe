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