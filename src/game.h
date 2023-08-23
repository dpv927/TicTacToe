#pragma once
/**
 * @brief Detects a exit signal with Ctrl+C.
 *
 * We need to know if a user unexpectedly closes or terminates the program in the
 * middle of a game. This is because the operating system's semaphores that are 
 * created at the beginning of the "start_game" function were originally not destroyed
 * until the end of the program, so if the user closed the application in the middle
 * of a game, they would never be destroyed. When the program is restarted, a failure
 * would occur when trying to create semaphores with the same ID as the existing ones
 * (which should have been eliminated).
 *
 * @param signum Signal number. **/
void sigint_handler(int signum);

/**
 * @brief Detects a exit signal with a kill command.
 * @see sigint_handler for a further explanation.
 *
 * @param signum Signal number. **/
void sigterm_handler(int signum);

/**
* @brief Deletes every resource created in the start_game function.
* @see start_game, sigterm_handler and sigterm_handler to see what delete_resources
* are we talking about. **/
void delete_resources();

/**
* @brief Starts a new game between two players.
* The players can be two people or one person against the AI.

* @param mode Game mode specified for the function. If mode
* is 0, then a game between the AI and a player will be created, while if
* mode is 1, a game for two players will be created. **/
void start_game(int mode, int maxAidepth);
