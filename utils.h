#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

/**@brief Reads the coordinates of a player's next move.
 * Depending on the player id, the output for the player will be
 * different. Used in main.c.
 * The function asks for the row and column of the move, repeating
 * itself if the output is less than 0 and greater than 2 (the rows
 * and columns go from 0 to 2). * 
 * @param id Player id**/
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

/**@brief Prints the game result.
 * @param id Player ID.
 * @param board Game board.
 * @param game_eval Final evaluation of the game. **/
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

/**@brief Copies a int array.
 * @param array Array to copy
 * @return Copy of the parameter array.*/
int* arrayCpy(int array[]) {
  int* copy = (int*) malloc(sizeof(int)*BOARD_LEN);
  for (int i = 0; i < BOARD_LEN; i++) {
    copy[i] = array[i];
  }
  return copy;
}