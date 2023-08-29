#include <stdio.h>
#include <stdlib.h>
#include "parameters.h"
#include "analysis.h"
#include "resources.h"
#include "game.h"

int main(int argc, char *argv[]) {

  // Check for number of parameter range
  if(argc > 5 || argc < 2) {
    nError(argc);
    exit(1);
  }
  
  // One parameter
  if(argc == 2) {
    if(equals(argv[1], "--version")) {
      // Show the program current version 
      printdoc("/etc/ttt/doc/version.txt"); // release path
      //printdoc("../doc/version.txt"); // testing path 
    }
    else if (equals(argv[1], "--help")){
      // Show the program commands and help
      printdoc("/etc/ttt/doc/help.txt"); // release path
      //printdoc("../doc/help.txt"); // testing path 
    }
    else if(equals(argv[1], "--player-mode")) {
      // Start a 1vs1 game (Human vs Human)
      start_game(1, 0);
    }
    else if(equals(argv[1], "--ai-mode")) {
      // Start a 1vs1 game (Human vs Ai) 
      start_game(0, 9);
    } else { pError(); }
  }

  // Two parameters
  else if(argc == 3) {
    if(equals(argv[1], "--search")) {
      // Start an analysis over a game state using the
      // default search depth (9 = max).
      search(argv[2], 9);
    } else { pError(); }
  }

  // Three parameters
  else if(argc == 4) {
    if(equals(argv[1], "--ai-mode") && equals(argv[2], "--max-depth")) {
      // Start a 1v1 game (Human vs AI) with custom
      // depth for the search tree.
      char* endptr;
      strtol(argv[3], &endptr, 10);

      if(*endptr == '\0') { // Valid number
        start_game(0, atoi(argv[3])) ;
      } else { vError(argv[3], argv[2]); }
    } else { pError(); }
  }

  // Four parameters
  else if(argc == 5) {
    if(equals(argv[1], "--search") && equals(argv[3], "--depth")) {
      // Start an analysis over a game state using a
      // custom search depth.
      char* endptr;
      strtol(argv[4], &endptr, 10);

      if(*endptr != '\0'){ // Not a number
        vError(argv[4], argv[3]); 
      }
      search(argv[2], atoi(argv[4]));
    }else { pError(); }
  }
  return 0;
}
