#pragma once
#include "game_info.h"

/* Function that searches the best move over the given board  at the
 * gstate string, wich also contains the player to maximize the next move.
 *
 * @param gstate Game state given by a string representation.
 * @param depth Selected depth to limit the search node depth.
 * */ 
void search(const char* gstate, const int depth);

/* Function that checks if the given game state board is valid and has
 * every element to continue the search.
 *
 * @param gstate Game state given by a string representation.
 * @param gstruct Game struct to initialize. 
 * */
void initGameState(const char* gstate, struct Game* gstruct);
