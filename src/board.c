#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "board.h"

void printgames(int board[]) {
  printf("+---+---+---+\n");
  
  for (int i = 0; i < BOARD_LEN; i++) {
    printf("| %c ", (board[i] == PLAYER_1)? 'x' : ((board[i] == PLAYER_2)? 'o' : ' '));
    
    if ((i + 1) % 3 == 0) 
      printf("|\n+---+---+---+\n");
  }
}


int* arrayCpy(int array[]) {
  int* copy = (int*) malloc(sizeof(int)*BOARD_LEN);
  for (int i = 0; i < BOARD_LEN; i++) {
    copy[i] = array[i];
  }
  return copy;
}

int boardIsFull(int board[]) {
  for (int i=0; i< BOARD_LEN; i++)
	  if (board[i] == PLAYER_N)
		  return 0;
	return 1;
}

int evaluateInStep(int start, int step, int board[]) {
 int pre_owner, end = start + step;

  for (int i = start; i <= end; i += step) {
			pre_owner = board[i-step];
			if (pre_owner == PLAYER_N || board[i] != pre_owner)
				return PLAYER_N;
			if (i == end)
				return (pre_owner == PLAYER_1)? PLAYER_1 : PLAYER_2;
		}
		return 0;
}

int evaluateGame(int board[]) {
  // Diagonal left up - right down
		int result = evaluateInStep(4, 4, board);
		if (result != PLAYER_N)
			return result;

		// Diagonal right up - left down
		result = evaluateInStep(4, 2, board);
		if (result != PLAYER_N)
			return result;

		// All the rows
		for (int i = 1; i <= 7; i += 3) {
			result = evaluateInStep(i, 1, board);
			if (result != PLAYER_N)
				return result;
		}

		// All the columns
		for (int i = 3; i <= 5; i += 1) {
			result = evaluateInStep(i, 3, board);
			if (result != PLAYER_N)
				return result;
		}
		return (boardIsFull(board))? COND_DRAW : COND_KEEP;
}

int** generateSucessors(int board[], int player) {
  int** sucessors = (int**) malloc(sizeof(int*)*BOARD_LEN);
  
  for (int i = 0; i < BOARD_LEN; i++) {
    if(board[i] != PLAYER_N) {
      sucessors[i] = NULL;
	  continue;
    }
	sucessors[i] = arrayCpy(board);
	sucessors[i][i] = player;
  }
  return sucessors;
}
