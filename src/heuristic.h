#pragma once

/* Constants to indicate whether a certain player has won
 * or lost the game (No evaluation = draw) */
static const int MAX_EVAL  =  100;
static const int MIN_EVAL  = -100;
static const int NO_EVAL   = 0;
static const int EVAL_KEEP = -1;

/**
 * @brief Calculates the heuristic value of the current board state.
 * 
 * This function calculates and returns the heuristic value of the current state of the game board.
 * 
 * @param board The game board.
 * @param bias A bias value indicating which player the evaluation is based on.
 * 
 * @return The heuristic value.
 */
int heuristic(int* board, const int bias);

/**
 * @brief Calculates the heuristic for a row/column/diagonal.
 * 
 * This function is used within the heuristic function to calculate the heuristic of each board section,
 * providing a more precise value for evaluation.
 * 
 * @param start The starting index of the row/column/diagonal.
 * @param step The number to reach the next index of the row/column/diagonal.
 * @param board The game board for which the heuristic is being calculated.
 * @param bias Indicates which player's perspective the evaluation is based on.
 * 
 * @return The heuristic value of the specified board section.
 */
int heuristicInStep(const int start, const int step, int* board, const int bias);

