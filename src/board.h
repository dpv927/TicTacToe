#ifndef BOARD_H
#define BOARD_H

#include "game.h"

/**
 * @brief Evaluates the current state of a board, determining if any player has won,
 * if there is a draw, or if there are more possible moves.
 *
 * @param g A pointer to a Game object representing the game state.
 *
 * @return A member of the GameState enumeration. If any player has won, the G_Victory
 * flag is returned. If the board is full (no more moves possible) and no player has won,
 * the G_Draw flag is returned. Otherwise, if there are more possible moves and no player
 * has won yet, the G_Keep flag is returned.
 */
enum GameState evaluateGame(struct Game* g);

/**
 * @brief Prints the board of a game.
 * 
 * @param g A pointer to a Game object representing the game state.
 */
void draw(struct Game* g);

#endif // !BOARD_H
