/** Macros **/
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

/**
 * @brief Reads the coordinates of a player's next move. Depending on the player
 * id, the output for the player will be different. Used in main.c. The function
 * asks for the row and column of the move, repeating itself if the output is
 * less than 0 and greater than 2 (the rows and columns go from 0 to 2).
 *
 * @param id Player id
 * **/
int readCoordinates(int id);

/**
 * @brief Prints the board of a game
 * @param board Game board
 * **/
void printGame(int board[]);

/**
 * @brief Prints the game result.
 * 
 * @param id Player ID.
 * @param board Game board.
 * @param game_eval Final evaluation of the game.
 * **/
void giveAndExit(int id, int* board, int game_eval);

/**
 * @brief Copies a int array.
 * 
 * @param array Array to copy
 * @return Copy of the parameter array.
 * */
int* arrayCpy(int array[]);

/**
 * @brief Frees the memory of a sucessors matrix. This function is called
 * in all the search functions because we need to free all the memory that its
 * occupied with the sucessors of a board state (they wont be used again).
 * To do so, we use new thread to be more efficient in the process, so This
 * function must delete the thread when finished.
 * @param array sucessors matrix. 
 * */
void* freeSucessorsMem(void* arg);
