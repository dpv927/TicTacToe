#pragma once
#include "player.h"

/* Enumeration that defines a game status. The three possible states are:
 * draw between the two players, a status where no one wins and there are
 * more possible moves and a status where some player won. */
enum GameState { G_Keep, G_Draw, G_Victory };

/* Struct that represents a game.
 * board: Game board. It contains numbers that represents the IDs of both
 * players in every cell of the board.
 *
 * t_index: Indicates wich player had the last turn of the game. Its 
 * value is the index 0 ir 1 of the players array.
 *
 * players: Array with two positions. In [0] is located player1 and in the
 * [1] position is located player2. 
 *
 * GameState: Member of the Enumeration GameState that indicates the actual
 * state of the game. */
struct Game {
  int board[9];
  int t_index;
  struct Player players[2];
};