/** Macros **/
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

/**
 * @brief Frees the memory of a sucessors matrix. This function is called
 * in all the search functions because we need to free all the memory that its
 * occupied with the sucessors of a board state (they wont be used again).
 * To do so, we use new thread to be more efficient in the process, so This
 * function must delete the thread when finished.
 * @param array sucessors matrix. 
 * */
void* freeSucessorsMem(void* arg);

/**
 * @brief Calculates the minimax algorithm over a board. Depending if the 
 * algorithm is maximizing returns the best or worst possible move for the `ñayer to move.
 * 
 * @param board Game board.
 * @param is_maximizing Determines if the algorithm has to maximize the move. (True (1) = best,
 * False (0) = worst.
 * @param player ID of the player to perform the move.
 * **/
int minimax(int* board, int is_maximizing, int player);

/**
 * @brief Calculates the alpha-beta algorithm (upgrade of minimax) over a board. Depending if the 
 * algorithm is maximizing returns the best or worst possible move for the `ñayer to move.
 * 
 * @param board Game board.
 * @param alpha Value of alpha to use in the current branch.
 * @param beta Value of beta to use in the current branch.
 * @param is_maximizing Determines if the algorithm has to maximize the move. (True (1) = best,
 * False (0) = worst.
 * @param player ID of the player to perform the move.
 * **/
int alphabeta(int* board, int alpha, int beta, int is_maximizing, int player);
