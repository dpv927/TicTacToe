#pragma once
/**
* @brief Function that manages the request for the next move from a player.
* @return Number of the square that the next move will occupy. **/
int player_asker(int player_id, int* board);

/**
* @brief Function that manages the request for the next move from the AI.
* @return Number of the square that the next move will occupy. **/
int ai_asker(int player_id, int* board);