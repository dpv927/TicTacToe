#ifndef SYNC_GAME_H
#define SYNC_GAME_H

#include "game.h"

/**
 * @brief Detects an exit signal triggered by Ctrl+C.
 *
 * This function is responsible for detecting if a user unexpectedly closes or terminates the program
 * in the middle of a game. It addresses a situation where the operating system's semaphores, created at
 * the beginning of the "start_game" function, were originally not destroyed until the end of the program.
 * If the user closed the application during a game, these semaphores wouldn't be destroyed, causing issues
 * when trying to create semaphores with the same ID upon restarting the program. This function helps avoid
 * such problems.
 *
 * @param signum The signal number.
 */
void sigint_handler(const int signum);

/**
 * @brief Detects an exit signal triggered by a kill command.
 * 
 * Similar to sigint_handler, this function detects an exit signal. For further details, refer to the explanation
 * provided in the sigint_handler function description.
 *
 * @param signum The signal number.
 */
void sigterm_handler(const int signum);

/**
 * @brief Deletes all resources created within the start_game function.
 * 
 * This function is responsible for cleaning up and deleting any resources that were created during the execution
 * of the start_game function. For additional context, refer to the start_game, sigint_handler, and sigterm_handler
 * descriptions.
 */
void delete_resources(void);

/**
 * @brief Initiates a new game between two players.
 * 
 * @param p1_mode Type of player for player1.
 * @param p2_mode Type of player for player2.
 * @param maxAidepth1 The maximum depth for player1's AI (if applicable).
 * @param maxAidepth1 The maximum depth for player2's AI (if applicable).
 */
void syncronized_game(enum PlayerType p1_mode, enum PlayerType p2_mode, uint8_t maxAidepth1, uint8_t maxAidepth2);

#endif // !SYNC_GAME_H
