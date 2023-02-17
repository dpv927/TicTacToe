#define BOARD_LEN 9

/*REturns 0 if its not full, 1 if it is*/
int boardIsFull(int board[]) {
  for (int i=0; i<9; i++)
	  if (board[i] == 0)
		  return 0;
	return 1;
}

/** Returns -1 if player 2 wins, 1 if player 1 does and 
 * 0 if no player wins at this point */
int evaluateInStep(int start, int step, int board[]) {
 int pre_owner, end = start + step;

  for (int i = start; i <= end; i += step) {
			pre_owner = board[i-step];
			if (pre_owner == 0 || board[i] != pre_owner)
				return 0;
			if (i == end)
				return (pre_owner == 2)? -1 : 1;
		}
		return 0;
}

/* Returns -1 if player2 wins, 1 if player1 does, 0 if 
 * there is a tie and -2 if no one wins and there are more
 * posible moves for the players.*/
int evaluateGame(int board[]) {
  // Diagonal left up - right down
		int result = evaluateInStep(4, 4, board);
		if (result != 0)
			return result;

		// Diagonal right up - left down
		result = evaluateInStep(4, 2, board);
		if (result != 0)
			return result;

		// All the rows
		for (int i = 1; i <= 7; i += 3) {
			result = evaluateInStep(i, 1, board);
			if (result != 0)
				return result;
		}

		// All the columns
		for (int i = 3; i <= 5; i += 1) {
			result = evaluateInStep(i, 3, board);
			if (result != 0)
				return result;
		}
		return (boardIsFull(board)==1)? 0 : -2;
}

void printGame(int board[]) {
  char c;
  printf("+---+---+---+\n");
  
  for (int i = 0; i < 9; i++) {
    c = (board[i] == 1)? 'x' : ((board[i] == 2)? 'o' : ' '); 

    if (i%3 == 0) {
      printf("| ");
    }
    printf("%c | ", c);
    
    if ((i + 1) % 3 == 0) {
      printf("\n+---+---+---+\n");
    }
  }
}
