#ifndef SEARCH_H
#define SEARCH_H

#include <stdint.h>

/** Macros **/
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

/**
 * @brief Calculates the minimax algorithm with alpha-beta pruning over a game board.
 *
 * The algorithm calculates and returns the best possible move for the player to make (AI).
 *
 * For detailed understanding, refer to the Wikipedia definitions of minimax:
 * (https://en.wikipedia.org/wiki/Minimax) and its advanced version, alpha-beta pruning:
 * (https://en.wikipedia.org/wiki/Alpha%E2%80%93beta_pruning).
 *
 * @param board The game board.
 * @param is_maximizing Determines whether the algorithm aims to maximize the move.
 * @param pmaxId The ID of the player to maximize.
 * @param pminId The ID of the opponent player to minimize.
 * @param depth The current node depth in the search tree.
 * @param maxdepth The maximum depth to reach in the search tree.
 * @param alpha The alpha value for alpha-beta pruning.
 * @param beta The beta value for alpha-beta pruning.
 *
 * @return The index of the best-calculated move.
 */
int alphabeta(const int is_maximizing, uint16_t pmax, uint16_t pmin, const int depth, const int maxdepth, int alpha, int beta);

#endif // !SEARCH_H
