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

/**
 * @brief Checks if an argument exists in the given parameters
 * 
 * @param str_to_find Parameter to find.
 * @param narg Number of arguments given to the program.
 * @param arg All the arguments given to the program.
 *
 * @return The index of the parameter if exists, -1 if its not found.
 */
int ExistsArg(char const *str_to_find, int narg, char** arg);

/* 
 * @brief Checks the number of arguments.
 *
 * @param argc Number of arguments given to the program.
 *
 * */
void CheckNumberArgs(int argc);

/* 
 * @brief Prints an error message due a bad argument 
 * */
void BadArgument();

/* @brief Prints an error message due a wrong value for a 
 * parameter.
 *
 * @param value Wrong value for the parameter.
 * @parameter Given parameter.
 * */
void BadArguments(const char* value, const char* parameter);

/* @brief Processes all the arguments and ninitializes 
 * the neccesary modules.
 *
 * @param argc Number of arguments given to the program.
 * @param argv All the arguments given to the program.
 * */
void ProcessArguments(int argc, char** argv);

#endif
