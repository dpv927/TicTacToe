#include <stdlib.h>
#include "constants.h"
#include "utils.h"
#include "board.h"

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
    if(board[i] == PLAYER_N) {
      board[i] = player;
      sucessors[i] = arrayCpy(board);
      board[i] = PLAYER_N;
    }
  }
  return sucessors;
}
