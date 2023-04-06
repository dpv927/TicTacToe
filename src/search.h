/** Macros **/
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

/**
 * @brief Calculates the minimax algorithm over a board. Depending if the 
 * algorithm is maximizing returns the best or worst possible move for the `ñayer to move.
 * 
 * @param board Game board.
 * @param is_maximizing Determines if the algorithm has to maximize the move. (True (1) = best,
 * False (0) = worst.
 * @param player ID of the player to perform the move.
 * **/
int minimax(int board[], int is_maximizing, int depth, int player_id);
