s/**
 * @brief Prints the board of a game
 * @param board Game board
 **/
void printGame(int board[]);

/**
* @brief Empieza una nueva partida entre dos jugadores.
* Los juagdores pueden ser dos personas o una persona contra la AI.
* @param mode Modo de juego que se le especifica a la funcion. Si mode
* es 0, entonces se creará un juego entre la AI y un jugador, mientras que si
* mode es 1, se creara una partida para dos jugadores.
**/
void start_game(int mode);