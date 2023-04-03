#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
//#include <pthread.h>
#include "constants.h"
#include "board.h"
#include "search.h"

/*
void* freeSucessorsMem(void* arg) {
  int **matrix = (int **) arg;
  for (int i = 0; i < BOARD_LEN; i++) {
    free(matrix[i]);
  }
  free(matrix);
  //pthread_exit(NULL);
  return NULL;
}
*/

int minimax(int* board, int is_maximizing, int player) {
  printf("Llega a minimaxº\n");

  int eval;
  int value;
  int** sucessors;
  
  eval = evaluateGame(board);
  if(eval != COND_KEEP) return eval;

  if(is_maximizing) {
    value = INT_MIN;
    sucessors = generateSucessors(board, player);

    for (int i = 0; i < BOARD_LEN; i++) {
      if(sucessors[i] != NULL)
        printf("No es null\n");
        //value = max(value, minimax(sucessors[i], 0, player));
    }
    exit(0);
  }
  else{
    value = INT_MAX;
    sucessors = generateSucessors(board, player);

    for (int i = 0; i < BOARD_LEN; i++) {
      if(sucessors[i] != NULL)
        value = min(value, minimax(sucessors[i], 1, player));
    }
  }
  //pthread_t tid;
  //pthread_create(&tid, NULL, freeSucessorsMem, sucessors);
  //pthread_join(tid, NULL);
  return value;
}

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
  //pthread_t tid;
  //pthread_create(&tid, NULL, freeSucessorsMem, sucessors);
  //pthread_join(tid, NULL);
  return value;
}
