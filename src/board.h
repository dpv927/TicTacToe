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
int evaluateInStep(int start, int step, int board[]);

/** @brief Evaluates the actual state of a board.
 * @param board Array that represents the game board.
 * @return -1 if player2 wins, 1 if player1 does, 0 if 
 * there is a tie and -2 if no one wins and there are more
 * posible moves for the players. **/
int evaluateGame(int board[]);

/**@brief Generates the sucessors of a state of a board.
 * The sucessors are made by marking the empty spots of
 * the board with the player parameter ID.
 * @param board Board to generate the sucessors.
 * @param player Player that is doing the move
 * @return Array of boards. **/
int** generateSucessors(int board[], int player);
