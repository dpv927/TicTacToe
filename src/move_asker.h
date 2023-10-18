#ifndef MOVE_ASKER_H
#define MOVE_ASKER_H

#include <stdint.h>
#include "game.h"

/**
 * @brief Manages the request for the next move from a player.
 * 
 * @param board Player ID.
 * @param depth Game state object.
 * 
 * @return The number of the square that the next move will occupy.
 */
uint8_t player_asker(const int pid, struct Game* g);

/**
 * @brief Manages the request for the next move from the AI.
 * 
 * @param pmaxBoard The bitboard of the player to maximize.
 * @param pminBoard The bitboard of the player to minimize.
 * @param depth The depth used for decision-making (if applicable).
 * 
 * @return The number of the square that the next move will occupy.
 */
uint8_t ai_asker(uint16_t pmaxBoard, uint16_t pminBoard, uint8_t depth);

#endif // !MOVE_ASKER_H
