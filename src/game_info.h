#pragma once
#include "player.h"

/* Enumeration that defines the game statuses. The three possible states are:
 * a draw between the two players, a status where no one wins and there are
 * more possible moves, and a status where some player won. */
enum GameState { G_Keep, G_Draw, G_Victory };

/* Struct that represents a game.
 * board: The game board. It contains numbers that represent the IDs of both
 * players in each cell of the board.
 *
 * t_index: Indicates which player had the last turn in the game. Its 
 * value is the index 0 or 1 of the players array.
 *
 * players: An array with two positions. Player 1 is located in [0], and player 2
 * is located in the [1] position.
 *
 * state: A member of the GameState enumeration that indicates the current
 * state of the game. */
struct Game {
  int board[9];
  int t_index;
  struct Player players[2];
  enum GameState state;
};

