/**
 * @brief Reads the coordinates of a player's next move. Depending on the player
 * id, the output for the player will be different. Used in main.c. The function
 * asks for the row and column of the move, repeating itself if the output is
 * less than 0 and greater than 2 (the rows and columns go from 0 to 2).
 *
 * @param id Player id
 * **/
int readCoordinates(int id);

/**
 * @brief Funcion que se encarga de gestionar la peticion de siguiente
 * movimiento a un jugador. 
 * @return Numero de casilla que ocupara el siguiente movimiento.
 */
int player_asker();