#pragma once

/* Player ID constants. These constants are used to represent
 * players on a game board. */
static const int PLAYER_1 = 0b010;
static const int PLAYER_2 = 0b101;
static const int PLAYER_N = 0b000;
static const int P_MASK   = 0b111;

/* Player representation characters. These constants are used to
 * visually display players on a game board. */
static const char DEF_P1_REP = 'x';
static const char DEF_P2_REP = 'o';

/* We need a way to represent a player's role in a human-readable format in the console. */
// static const char* PTypes[] = { "Ai", "Human" };

/* Struct that represents a player in the program.
 * type: A member from the PlyrType enumeration, indicating if the player
 *       is an AI or a human.
 *
 * pl_rep: A character that represents, in a human-readable format, what the player
 *         looks like on a game board. Refer to the DEF_P* constants for more information.
 *
 * id: An integer that represents a player on a game board. Refer to the PLAYER_*
 *     constants for more information. 
 * */
struct Player {  
  enum PlayerType {
    Ai, Human  
  } type;
  char pl_rep;
  int id;
};
