#pragma once
/** Macros **/
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

/**
 * @brief Calculates the minimax algorithm over a board. Depending if the 
 * algorithm is maximizing returns the best or worst possible move for the player to move.
 *
 * @param board Game board.
 * @param is_maximizing Determines if the algorithm has to maximize the move.
 * @param pmaxId Id of the player to maximize.
 * @param pminId Id of the player to minimize.
 * @param depth Current node depth in the search tree.
 * @param maxdepth Maximum depth to reach in the search tree.
 * 
 * @returns Index of the best calculated move. **/
int minimax(int* board, int is_maximizing, int pmaxId, int pminId, int depth, int maxdepth);
