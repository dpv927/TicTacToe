#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "parameters.h"
#include "analysis.h"
#include "resources.h"
#include "sync_game.h"
#include "argshand.h"

#define ONLY_ONE_ARG 2
#define NUM_GAME_ARG 4

/* Some Argument info */
int param_index;

typedef struct {
  uint8_t search_depth;
  uint8_t used;
} Search;

typedef struct {
  uint8_t search_depth_P1;
  uint8_t search_depth_P2;
  enum PlayerType p1_type;
  enum PlayerType p2_type;
  uint8_t used;
} Versus;
/* End of variables */

int main(int argc, char *argv[]) {

  if(argc < ONLY_ONE_ARG) {
    nError(argc);
    exit(EXIT_FAILURE);}

  /* ---- Version information ---- */
  if(ExistArg("--version", argc, argv) && argc == ONLY_ONE_ARG ) {
    printdoc("/etc/ttt/doc/version.txt");
    //printdoc("../doc/version.txt"); // testing path 
    exit(EXIT_SUCCESS);}
  
  /* ---- Help message ---- */
  if(ExistArg("--help", argc, argv) && argc == ONLY_ONE_ARG) {
    printdoc("/etc/ttt/doc/version.txt");
    //printdoc("../doc/help.txt"); // testing path 
    exit(EXIT_SUCCESS);}


  /* --- Argument info initialization ---  */
  Search s_info = { 9, 0 };
  Versus vs_info = { 9, 9, 0, 0, 0 };
  /* --- Argument info initialization ---  */


  /* ---- Search Depth ---- */
  if((param_index = ExistArg("--search-depth", argc, argv))) {
    if(param_index == argc-1) pError();

    char* endptr;
    strtol(argv[param_index+1], &endptr, 10);

    if(*endptr == '\0') { 
      s_info.search_depth = atoi(argv[param_index+1]);
      s_info.used = 1;
    } else { vError(argv[param_index+1], argv[param_index]); }
  }

  /* ---- Search Depth for Ai player1 (Only 1vs1) ---- */
  if((param_index = ExistArg("--depth-Ai1", argc, argv))) {
    if(s_info.used || param_index == argc-1) pError();
    
    char* endptr;
    strtol(argv[param_index+1], &endptr, 10);

    if(*endptr == '\0') { 
      vs_info.search_depth_P1 = atoi(argv[param_index+1]);
      vs_info.used = 1;
    } else { vError(argv[param_index+1], argv[param_index]); }
  }

  /* ---- Search Depth for Ai player2 (Only 1vs1) ---- */
  if((param_index = ExistArg("--depth-Ai2", argc, argv))) {
    if(s_info.used || param_index == argc-1) pError();

    char* endptr;
    strtol(argv[param_index+1], &endptr, 10);

    if(*endptr == '\0') { 
      vs_info.search_depth_P1 = atoi(argv[param_index+1]);
      vs_info.used = 1;
    } else { vError(argv[param_index+1], argv[param_index]); }
  }

  /* ---- Type of player of player1 (Only 1vs1) ---- */
  if((param_index = ExistArg("--p1-type", argc, argv))) {
    if(s_info.used || param_index == argc-1) pError();

    if(!strcmp(argv[param_index+1], "Human")) {
      vs_info.p1_type = Human;
      vs_info.used = 1;
    } else if(!strcmp(argv[param_index+1], "Ai")) {
      vs_info.p1_type = Ai;
      vs_info.used = 1;
    }else vError(argv[param_index+1], argv[param_index]); 
  }

  /* ---- Type of player for player2 (Only 1vs1) ---- */
  if((param_index = ExistArg("--p2-type", argc, argv))) {
    if(s_info.used || param_index == argc-1) pError();

    if(!strcmp(argv[param_index+1], "Human")) {
      vs_info.p2_type = Human;
      vs_info.used = 1;
    } else if(!strcmp(argv[param_index+1], "Ai")) {
      vs_info.p2_type = Ai;
      vs_info.used = 1;
    }else vError(argv[param_index+1], argv[param_index]); 
  }

  /* ---- Start Sybcronyzed game? ---- */
  if((ExistArg("--versus", argc, argv))) {
    if(s_info.used) pError();
    syncronized_game(vs_info.p1_type, vs_info.p2_type, vs_info.search_depth_P1, vs_info.search_depth_P2); }

  /* ---- Start Best Move Search? ---- */
  if((param_index = ExistArg("--bestmove", argc, argv))) {
    if(vs_info.used) pError();
    search(argv[param_index], s_info.search_depth); }
  
  return 0;
}
