#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argshand.h"
#include "game.h"
#include "resources.h"
#include "sync_game.h"
#include "analysis.h"

void CheckNumberArgs(int argc) {
  if(argc < MIN_NUM_ARG) {
    fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0mInvalid number of arguments (%d)!\nexiting...\n", argc-1);
    exit(EXIT_FAILURE);
  }
}

void BadArgument() {
  fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0mUnrecognized option/s or bad placement.\nexiting...\n");
  exit(EXIT_FAILURE);
}

void BadArguments(const char* value,const char* parameter) {
  fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0m%s: Not a value for the option '%s'.\nexiting...\n", value, parameter);
  exit(EXIT_FAILURE);
}

void ProcessArguments(int argc, char** argv) {

  /* ---- Version information ---- */
  if(ExistsArg("--version", argc, argv) && argc == MIN_NUM_ARG) {
    //printdoc("/etc/ttt/doc/version.txt");
    printdoc("../doc/version.txt"); // testing path 
    exit(EXIT_SUCCESS);}
  
  /* ---- Help message ---- */
  if(ExistsArg("--help", argc, argv) && argc == MIN_NUM_ARG) {
    //printdoc("/etc/ttt/doc/version.txt");
    printdoc("../doc/help.txt"); // testing path 
    exit(EXIT_SUCCESS);}


  /* --- Argument info initialization ---  */
  int param_index;
  struct Search s_info = {9,0};
  struct Versus vs_info = {9,9,Human,Human,0};
  /* --- Argument info initialization ---  */


  /* ---- Search Depth ---- */
  if((param_index = ExistsArg("--search-depth", argc, argv))) {
    if(param_index == argc-1) BadArgument();

    char* endptr;
    strtol(argv[param_index+1], &endptr, 10);

    if(*endptr == '\0') { 
      s_info.search_depth = atoi(argv[param_index+1]);
      s_info.used = 1;
    } else { BadArguments(argv[param_index+1], argv[param_index]); }
  }

  /* ---- Search Depth for Ai player1 (Only 1vs1) ---- */
  if((param_index = ExistsArg("--depth-Ai1", argc, argv))) {
    if(s_info.used || param_index == argc-1) BadArgument();
    
    char* endptr;
    strtol(argv[param_index+1], &endptr, 10);

    if(*endptr == '\0') { 
      vs_info.search_depth_P1 = atoi(argv[param_index+1]);
      vs_info.used = 1;
    } else { BadArguments(argv[param_index+1], argv[param_index]); }
  }

  /* ---- Search Depth for Ai player2 (Only 1vs1) ---- */
  if((param_index = ExistsArg("--depth-Ai2", argc, argv))) {
    if(s_info.used || param_index == argc-1) BadArgument();

    char* endptr;
    strtol(argv[param_index+1], &endptr, 10);

    if(*endptr == '\0') { 
      vs_info.search_depth_P1 = atoi(argv[param_index+1]);
      vs_info.used = 1;
    } else { BadArguments(argv[param_index+1], argv[param_index]); }
  }

  /* ---- Type of player of player1 (Only 1vs1) ---- */
  if((param_index = ExistsArg("--p1-type", argc, argv))) {
    if(s_info.used || param_index == argc-1) BadArgument();

    if(!strcmp(argv[param_index+1], "Human")) {
      vs_info.p1_type = Human;
      vs_info.used = 1;
    } else if(!strcmp(argv[param_index+1], "Ai")) {
      vs_info.p1_type = Ai;
      vs_info.used = 1;
    }else BadArguments(argv[param_index+1], argv[param_index]); 
  }

  /* ---- Type of player for player2 (Only 1vs1) ---- */
  if((param_index = ExistsArg("--p2-type", argc, argv))) {
    if(s_info.used || param_index == argc-1) BadArgument();

    if(!strcmp(argv[param_index+1], "Human")) {
      vs_info.p2_type = Human;
      vs_info.used = 1;
    } else if(!strcmp(argv[param_index+1], "Ai")) {
      vs_info.p2_type = Ai;
      vs_info.used = 1;
    }else BadArguments(argv[param_index+1], argv[param_index]); 
  }

  /* ---- Start Sybcronyzed game? ---- */
  if((ExistsArg("--versus", argc, argv))) {
    if(s_info.used) BadArgument();
    syncronized_game(vs_info.p1_type, vs_info.p2_type, vs_info.search_depth_P1, vs_info.search_depth_P2); }

  /* ---- Start Best Move Search? ---- */
  if((param_index = ExistsArg("--bestmove", argc, argv))) {
    if(vs_info.used) BadArgument();
    search(argv[param_index], s_info.search_depth); }
}

int ExistsArg(char const *str_to_find, int narg, char **arg) {
  for(short i=0;i<narg;i++)
    if (!strcmp(arg[i], str_to_find)) 
      return i;
  return 0;
}
