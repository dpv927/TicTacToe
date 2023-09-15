#pragma once

/**
 * @brief Manages the request for the next move from a player.
 * 
 * @param player_id The ID of the player making the move.
 * @param board The game board represented as an array.
 * @param depth The depth used for decision-making (if applicable).
 * 
 * @return The number of the square that the next move will occupy.
 */
int player_asker(const int player_id, int* board);

/**
 * @brief Manages the request for the next move from the AI.
 * 
 * @param player_id The ID of the AI player making the move.
 * @param board The game board represented as an array.
 * @param depth The depth used for decision-making (if applicable).
 * 
 * @return The number of the square that the next move will occupy.
 */
int ai_asker(const int player_id, int* board, const int depth);

