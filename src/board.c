#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "constants.h"
#include "board.h"

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

int evaluateInStep(int start, int step, int board[], int bias) {
 int pre_owner = 0;

  for (int i = start; i <= start + step; i += step) {
			pre_owner = board[i-step];
			if (pre_owner == PLAYER_N || board[i] != pre_owner)
				return PLAYER_N;
		}
		return (pre_owner == bias)? INT_MAX : INT_MIN;
}

int evaluateGame(int board[], int bias) {
  		// Diagonal left up - right down
		int result = evaluateInStep(4, 4, board, bias);
		if (result != PLAYER_N)
			return result;

		// Diagonal right up - left down
		result = evaluateInStep(4, 2, board, bias);
		if (result != PLAYER_N)
			return result;

		// All the rows
		for (int i = 1; i <= 7; i += 3) {
			result = evaluateInStep(i, 1, board, bias);
			if (result != PLAYER_N)
				return result;
		}

		// All the columns
		for (int i = 3; i <= 5; i += 1) {
			result = evaluateInStep(i, 3, board, bias);
			if (result != PLAYER_N)
				return result;
		}
		return (boardIsFull(board))? COND_DRAW : COND_KEEP;
}

void printBoard(int board[]) {
  printf("┌───┬───┬───┐\n");

  for (int i = 0; i < BOARD_LEN; i++) {
    printf("│ %c ", (board[i] == PLAYER_1)? 'x' : ((board[i] == PLAYER_2)? 'o' : ' '));
    
    if (i == 2 || i == 5) 
      printf("│\n├───┼───┼───┤\n");
  }
  printf("│\n└───┴───┴───┘\n");
}

