#ifndef MOVE_ASKER_H
#define MOVE_ASKER_H

#include <stdint.h>
#include "game.h"

/**
 * @brief Manages the request for the next move from a player.
 * 
 * @param player_id The ID of the player making the move.
 * @param board The game board represented as an array.
 * @param depth The depth used for decision-making (if applicable).
 * 
 * @return The number of the square that the next move will occupy.
 */
uint8_t player_asker(const int pid, struct Game* g);

/**
 * @brief Manages the request for the next move from the AI.
 * 
 * @param player_id The ID of the AI player making the move.
 * @param board The game board represented as an array.
 * @param depth The depth used for decision-making (if applicable).
 * 
 * @return The number of the square that the next move will occupy.
 */
uint8_t ai_asker(uint16_t pmaxBoard, uint16_t pminBoard, uint8_t depth);

#endif // !MOVE_ASKER_H
