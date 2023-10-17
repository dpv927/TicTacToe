#ifndef ARGSHAND_H
#define ARGSHAND_H

#include <stdint.h>
#include "game.h"

/* Min num. of arguments */
#define MIN_NUM_ARG       2

/* All the arguments */
#define VERSION_ARG       "--version"
#define HELP_ARG          "--help"
#define SEARCH_DEPTH_ARG  "--search-depth"
#define AI1_DEPTH_ARG     "--depth-Ai1"    
#define AI2_DEPTH_ARG     "--depth-Ai2"    
#define P1_TYPE_ARG       "--p1-type"    
#define P2_TYPE_ARG       "--p2-type"
#define VERSUS_ARG        "--versus"
#define SEARCH_ARG        "--bestmove"

struct Search {
  uint8_t search_depth;
  uint8_t used;
};

struct Versus {
  uint8_t search_depth_P1;
  uint8_t search_depth_P2;
  enum PlayerType p1_type;
  enum PlayerType p2_type;
  uint8_t used;
};

/* Checks if an argument exists in the given parameters */
int ExistsArg(char const *str_to_find, int narg, char **arg);

/* Check the number of arguments */
void CheckNumberArgs(int argc);

/* Prints an error message due a bad argument */
void BadArgument();

/* Prints an error message due a wrong value for a parameter */
void BadArguments(const char* value,const char* parameter);

/* Process all the arguments and get info */
void ProcessArguments(int argc, char** argv);

#endif
