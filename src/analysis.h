#pragma once
#include "game_info.h"

/* This function searches for the best move on the given board in the
 * game state string, which also includes the player who needs to maximize the next move.
 *
 * @param gstate A string representation of the game state.
 * @param depth The selected depth to limit the search node depth.
 */
void search(const char* gstate, const int depth);

/* This function checks if the given game state board is valid and contains
 * all the necessary elements to continue the search.
 *
 * @param gstate A string representation of the game state.
 * @param gstruct A Game struct to be initialized.
 */
void initGameState(const char* gstate, struct Game* gstruct);

