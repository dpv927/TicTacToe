#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "resources.h"
#include "game.h"

int main(int argc, char *argv[]) {

  if(argc != 2) {
    fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0mInvalid number of arguments!\nexiting...\n");
    exit(1);
  }
  if (strcmp(argv[1], "--version") == 0){
    printdoc("../doc/version.txt"); 
    exit(0);
  } 
  else if (strcmp(argv[1], "--help") == 0){
    printdoc("../doc/help.txt");
    exit(0);
  }

  if(strcmp(argv[1], "--player-mode") == 0) {
    start_game(1);
  } 
  else if(strcmp(argv[1], "--ai-mode") == 0) {
    start_game(0);
  }
  else {
    fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0mUnrecognized option: %s\nexiting...\n", argv[1]);
  }
  return 0;
}
