#pragma once
#include <stdio.h>
#include "game_info.h"

/**
 * @brief Returns 0 if the board is not full, and 1 if it is. This function
 * is used in the 'evaluateGame()' function to determine if a game ended in a draw or if there are more possible moves.
 * 
 * @param board An array representing the game board.
 * 
 * @return An integer value used as a boolean (1 = true, 0 = false).
 */
int boardIsFull(const int* board);

/**
 * @brief Evaluates a group of consecutive cells in a board array. This function is used in 'evaluateGame()'.
 * 
 * @param start The start index of a cell in the board.
 * @param step The step value indicating how many cells to move to reach the next consecutive cell.
 * @param end The end index of the group of cells to be evaluated.
 * @param board An array representing the game board.
 *
 * @returns A member of the GameState enumeration. It can be G_Keep if no one wins, or G_Victory if a player has 3 consecutive cells in the evaluated group of cells.
 */
enum GameState evaluateInStep(const int start, const int step, const int end, const int* board);

/**
 * @brief Evaluates the current state of a board, determining if any player has won, if there is a draw, or if there are more possible moves.
 *
 * @param board An array representing the game board.
 *
 * @return A member of the GameState enumeration. If any player has won, the G_Victory flag is returned. If the board is full (no more moves possible) and no player has won, the G_Draw flag is returned. Otherwise, if there are more possible moves and no player has won yet, the G_Keep flag is returned.
 */
enum GameState evaluateGame(const int* board);

/**
 * @brief Prints the board of a game.
 * 
 * @param g A struct representing the game board.
 */
void printBoard(const struct Game g);

