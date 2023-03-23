#include "game.h"
#define BOARD_LEN 9

/** @brief Returns 0 if the board it not full, 1 if it is.
 * @param board Array that represents the game board */
int boardIsFull(int board[]) {
  for (int i=0; i< BOARD_LEN; i++)
	  if (board[i] == PLAYER_N)
		  return 0;
	return 1;
}

/** @brief Evaluates a a group of consecutive cells from
 * a board.
 * @param start Start index of a cell in the board.
 * @param step In how many cells is the next consecutive cells.
 * @param board Array that represents the game board.
 * @returns -1 if player 2 wins, 1 if player 1 does and 
 * 0 if no player wins at this point. */
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

/* @brief Evaluates the actual state of a board.
 * @param board Array that represents the game board.
 * @return -1 if player2 wins, 1 if player1 does, 0 if 
 * there is a tie and -2 if no one wins and there are more
 * posible moves for the players. */
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
		return (boardIsFull(board))? COND_DRAW : COND_NOTH;
}

/**@brief Prints the board of a game**/
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
