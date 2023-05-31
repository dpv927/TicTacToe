/* Constants to indicate wether a determined player won
 * or lose the game */
static const int MAX_EVAL =  4096;
static const int MIN_EVAL = -4096;
static const int NO_EVAL  = 0;

/* Constants used in the heuristic function to indicate
 * the score of a player in a row. */
static const int Pscores[] = {
  0,        // No pieces at a row/column/diagonal
  256,      // One piece 
  1024,     // Two pieces
};

/** @brief Function that calculates the heristic value for a given row, column
 * or diagonal. The value returned is part of the heuristic calculated at the
 * heuristic(int* board, int bias) function.
 *
 * @param board Game board to evaluate.
 * @param start Start index of the secuence of cells.
 * @param step Index step or 'separation' between two cells in the secuence.
 * @param end End index of the secuence.
 * @bias Id from the player that we want to know its evaluation.
 *
 * @return Part of the total heuristic function that is calculated over a state
 * of a game board, because this function only gets the evaluation of a secuence
 * of cells in that game board. **/
int heuristicInStep(int* board, int start, int step, int end, int bias);

/** @brief function that calculates the heuristic for the AIs.
 *  @board Game board.
 *  @bias Id of the player that we want to know its evaluation. 
 *  @return Heuristic (evaluation value) that indicates wether a game
 *  state is favorable for the player represented with the Id 'bias' or not.
 *  The bigger the evaluation number is, the better a state is for the player. **/
int heuristic(int* board, int bias);
