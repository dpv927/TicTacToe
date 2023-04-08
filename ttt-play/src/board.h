/**
 * @brief Copies a int array.
 * @param array Array to copy
 * @return Copy of the parameter array.
 * */
int* arrayCpy(int array[]);

/** @brief Returns 0 if the board it not full, 1 if it is.
 * @param board Array that represents the game board */
int boardIsFull(int board[]);

/** @brief Evaluates a a group of consecutive cells from
 * a board.
 * @param start Start index of a cell in the board.
 * @param step In how many cells is the next consecutive cells.
 * @param board Array that represents the game board.
 * @returns -1 if player 2 wins, 1 if player 1 does and 
 * 0 if no player wins at this point. */
int evaluateInStep(int start, int step, int board[], int bias);

/** @brief Evaluates the actual state of a board.
 * @param board Array that represents the game board.
 * @param bias Bias applied to the evaluation.
 * @return -INF if the player that has a different ID that the bias 
 * parameter wins, INF if player with an ID same as the bias does, 0 
 * if there is a tie and -2 if no one wins and there are more posible
 * moves for the players. **/
int evaluateGame(int board[], int bias);

/**
* @brief Prints the board of a game
* @param board Game board
**/
void printBoard(int board[]);
