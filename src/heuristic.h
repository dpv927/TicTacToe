#pragma once
/* Constants to indicate wether a determined player won
 * or lose the game (No eval = draw) */
static const int MAX_EVAL  =  100;
static const int MIN_EVAL  = -100;
static const int NO_EVAL   = 0;
static const int EVAL_KEEP = -1;

/* @brief Gets the heuristic value of the current board state.
 * @param board Game board
 * @returns Heuristic value. */
int heuristic(int* board, int bias);
