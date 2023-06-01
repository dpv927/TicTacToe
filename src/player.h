#pragma once
/* Player IDs constants. This ones are used to represent
 * a player in a game board. */
static const int PLAYER_1  = 1;
static const int PLAYER_2  = 2;
static const int PLAYER_N  = 0;

/* Player representation chars. This constants are used to
 * show in a graphic a player into the game board. */
static const char DEF_P1_REP = 'x';
static const char DEF_P2_REP = 'o';

/* Enumeration that defines what role has a player in a game.
 * A player could be a human, or the machine. */
enum PlyrType { Ai, Human };

/* We need a way to represent the role of a player into the 
 * console, so its human readable. */
// static const char* PTypes[] = { "Ai","Human" };

/* Struct that represents a player in the program.
 * asker: Pointer to a function that gets a move from the player 
 * (f.e: if the player is human, the function will use stdin(), and
 * if the player is an AI, it will use a minimax to get the 'best' move.
 *
 * type: Member from the PlyrType enumeration. It tells if the player
 * is an AI or a human.
 *
 * pl_rep: Character that represents in a human readable mode what player
 * looks like in a game board. Check the DEF_P* constants for more info.
 *
 * id: Integer that represents a player in a board. Check the PLAYER_*
 * constants for more info. */
struct Player {
  int (*asker)(int, int*);
  enum PlyrType type;
  char pl_rep;
  int id; 
};
