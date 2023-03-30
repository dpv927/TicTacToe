#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "constants.h"
#include "utils.h"

int readCoordinates(int id) {
  int alias = (id == PLAYER_1)? 1 : 2;
  int x = -1;
  int y = -1;

  while(x<0 || x>2 || y<0 || y>2) {
    printf("\nPlayer%d ┌──────────── Row: ", alias);
    scanf("%d", &x);
    printf("────────┤\n        └───────── Column: ");
    scanf("%d", &y);
    fflush(stdin);
  }
  return x*3+y;
}

void printGame(int board[]) {
  char c;
  printf("+---+---+---+\n");
  
  for (int i = 0; i < 9; i++) {
    c = (board[i] == PLAYER_1)? 'x' : ((board[i] == PLAYER_2)? 'o' : ' '); 

    if (i%3 == 0) {
      printf("| ");
    }
    printf("%c | ", c);
    
    if ((i + 1) % 3 == 0) {
      printf("\n+---+---+---+\n");
    }
  }
}

void giveAndExit(int id, int* board, int game_eval) {
  if(id != PLAYER_1) return;
  printf("\nAfter the last move, the board state is:\n");
  printGame(board);
    
  switch (game_eval) {
    case PLAYER_1: printf("Player1 wins! :)\n\n");
      break;
    case PLAYER_2: printf("Player2 wins! :)\n\n");
      break;
     case COND_DRAW: printf("Its a draw! :O\n\n");
  }
}

int* arrayCpy(int array[]) {
  int* copy = (int*) malloc(sizeof(int)*BOARD_LEN);
  for (int i = 0; i < BOARD_LEN; i++) {
    copy[i] = array[i];
  }
  return copy;
}

void* freeSucessorsMem(void* arg) {
  int **matrix = (int **) arg;
  for (int i = 0; i < BOARD_LEN; i++) {
    free(matrix[i]);
  }
  free(matrix);
  pthread_exit(NULL);
}
