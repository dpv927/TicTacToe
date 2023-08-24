#pragma once
/** Macros **/
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

/**
 * @brief Calculates the minimax algorithm (alpha-beta variation) over a board. The algorithm
 * calculates and returns the best possible move for the player to move (AI).
 *
 * @see Wikipedia definition of minimax (https://en.wikipedia.org/wiki/Minimax) and its upgrade
 * called alpha-beta prunning (https://en.wikipedia.org/wiki/Alpha%E2%80%93beta_pruning).
 *
 * @param board Game board.
 * @param is_maximizing Determines if the algorithm has to maximize the move.
 * @param pmaxId Id of the player to maximize.
 * @param pminId Id of the player to minimize.
 * @param depth Current node depth in the search tree.
 * @param maxdepth Maximum depth to reach in the search tree.
 * @param alpha Alpha value. Used to see if its possible to do a alpha cutoff.
 * @param beta Beta value. Used to see if its possible to do a beta cuttof.
 *
 * @returns Index of the best calculated move. **/
int alphabeta(int* board, int is_maximizing, int pmaxId, int pminId, int depth, int maxdepth, int alpha, int beta);
