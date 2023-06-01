#include <stdio.h>
#include "board.h"
#include "board_info.h"

int boardIsFull(int board[]) {
  for (int i=0; i< BOARD_LEN; i++)
	  if (board[i] == PLAYER_N)
		  return 0;
	return 1;
}

enum GameState evaluateInStep(int start, int step, int end, int* board) {
  int counter = 1;
  int player = board[start];
  int actual;

  for (int i = start + step; i <= end; i += step) {
	  actual = board[i];

    if(actual == PLAYER_N) {
      counter = 0;
      continue;
    }
    if(actual != player) {
      counter = 1;
      player = actual;
      continue;
    }
    if(++counter == 3) {
      return G_Victory;
    }
  }
  return G_Keep;
}

enum GameState evaluateGame(int* board) {
		enum GameState result;

    // Diagonal left up - right down
    result = evaluateInStep(0, 4, 8, board);
		if (result != G_Keep)
			return result;

		// Diagonal right up - left down
		result = evaluateInStep(2, 2, 6, board);
		if (result != G_Keep)
			return result;

		// All the rows
		for (int i = 0; i <= 6; i += 3) {
			result = evaluateInStep(i, 1, i+2, board);
			if (result != G_Keep)
				return result;
		}

		// All the columns
		for (int i = 0; i <= 2; i ++) {
			result = evaluateInStep(i, 3, i+6, board);
			if (result != G_Keep)
				return result;
		}
		return (boardIsFull(board))? G_Draw : G_Keep;
}

void printBoard(struct Game g) {
  struct Player* p1 = &g.players[0];
  struct Player* p2 = &g.players[1]; 

  printf("     0   1   2\n   ┌───┬───┬───┐ Player1: '%c' \n", p1->pl_rep);

  for (int i = 0; i < BOARD_LEN; i++) {
    if(i%3 == 0) { printf(" %d ", i/3); }

    printf("│ %c ", (g.board[i] == p1->id)? p1->pl_rep : 
           ((g.board[i] == p2->id)? p2->pl_rep : ' '));  
    
    if(i == 5) {
      printf("│\n   ├───┼───┼───┤\n");
    }
    if (i == 2) { 
      printf("│ Player2: '%c'\n   ├───┼───┼───┤\n", p2->pl_rep); 
    }
  }
  printf("│\n   └───┴───┴───┘\n");
}
