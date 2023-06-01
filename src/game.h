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
* @brief Empieza una nueva partida entre dos jugadores.
* Los juagdores pueden ser dos personas o una persona contra la AI.
* @param mode Modo de juego que se le especifica a la funcion. Si mode
* es 0, entonces se creará un juego entre la AI y un jugador, mientras que si
* mode es 1, se creara una partida para dos jugadores. **/
void start_game(int mode);
