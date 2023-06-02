#pragma once
#include <stdio.h>
#include "game_info.h"

/**
 * @brief Returns 0 if the board it not full, 1 if it is. This function
 * is used in the 'evaluateGame()' function in order to determine if a 
 * game ended up with a draw or there are more possible moves.
 * 
 * @param board Array that represents the game board.
 * 
 * @return Integer value that must be used as a boolean. 
 * (1 = true, 0 = false). **/
int boardIsFull(int* board);

/**
 * @brief Evaluates a group of consecutive cells from
 * a board array. This function is used in 'evaluateGame()'.
 * 
 * @param start Start index of a cell in the board.
 * @param step In how many cells is the next consecutive cells.
 * @param board Array that represents the game board.
 *
 * @returns member of the GameState enumeration. It can be 
 * G_Keep if no one wins, G_Victory if some player has 3 consecutive
 * cells in the evaluated group of cells. **/
enum GameState evaluateInStep(int start, int step, int end, int* board);

/**
 * @brief Evaluates the actual state of a board. It determines if 
 * any player won, if there is a draw or there are more possible moves.
 *
 * @param board Array that represents the game board.
 *
 * @return Member of the GameState enumeration. If any player won, the
 * G_Victory flag is returned. If the board is full (there are no more moves)
 * and no one won, the G_Draw flag is returned. Else, there are more possible 
 * moves in the game and no one won, so the G_Keep flag is returned. **/
enum GameState evaluateGame(int* board);

/**
* @brief Prints the board of a game
* @param board Game board **/
void printBoard(struct Game g);