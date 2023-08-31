#pragma once

/* Player ID constants. These constants are used to represent
 * players on a game board. */
static const int PLAYER_1  = 1;
static const int PLAYER_2  = 2;
static const int PLAYER_N  = 0;

/* Player representation characters. These constants are used to
 * visually display players on a game board. */
static const char DEF_P1_REP = 'x';
static const char DEF_P2_REP = 'o';

/* Enumeration that defines a player's role in a game.
 * A player can be a human or the machine (AI). */
enum PlyrType { Ai, Human };

/* We need a way to represent a player's role in a human-readable format in the console. */
static const char* PTypes[] = { "AI", "Human" };

/* Struct that represents a player in the program.
 * asker: Pointer to a function that retrieves a move from the player.
 *        For example, if the player is human, the function will use stdin(),
 *        while if the player is an AI, it will use a minimax algorithm to find the 'best' move.
 *
 * type: A member from the PlyrType enumeration, indicating if the player
 *       is an AI or a human.
 *
 * pl_rep: A character that represents, in a human-readable format, what the player
 *         looks like on a game board. Refer to the DEF_P* constants for more information.
 *
 * id: An integer that represents a player on a game board. Refer to the PLAYER_*
 *     constants for more information. */
struct Player {
  int (*asker)(int, int*, int);
  enum PlyrType type;
  char pl_rep;
  int id;
};

