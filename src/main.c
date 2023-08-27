#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analysis.h"
#include "resources.h"
#include "game.h"

int main(int argc, char *argv[]) {

  if(argc > 4 || argc < 2) {
    fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0mInvalid number of arguments!\nexiting...\n");
    exit(1);
  }

  if(argc == 2) {
    if (strcmp(argv[1], "--version") == 0){
      printdoc("/etc/ttt/doc/version.txt"); // release path
      //printdoc("../doc/version.txt"); // testing path 
      exit(0);
    } 
    if (strcmp(argv[1], "--help") == 0){
      printdoc("/etc/ttt/doc/help.txt"); // release path
      //printdoc("../doc/help.txt"); // testing path 
      exit(0);
    }
    if(strcmp(argv[1], "--player-mode") == 0) {
      start_game(1, 9);
    } else if(strcmp(argv[1], "--ai-mode") == 0) {
      start_game(0, 9);
    } else {
      fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0mUnrecognized option: %s\nexiting...\n", argv[1]);
    }
  }
  else if(argc == 3) {
    if(strcmp(argv[1], "--search") == 0) {
       // call analysis func with argv[2] as FEN
    }else {
      fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0mUnrecognized option: %s\nexiting...\n", argv[1]);
    }
  }
  else if(argc == 4) {
    if(strcmp(argv[1], "--ai-mode") == 0) {
      if(strcmp(argv[2], "--max-depth") == 0) {
        start_game(0, atoi(argv[3]));
      } 
    }
  }
  else if(argc == 5) {
    if(strcmp(argv[1], "--search") == 0) {
      if(strcmp(argv[3], "--depth") == 0) {
        // call analysis func with argv[2] as FEN and argv[4]
        // as depth.
      }
      else {
        fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0mUnrecognized option: %s\nexiting...\n", argv[3]);
      }
    }else {
      fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0mUnrecognized option: %s\nexiting...\n", argv[1]);
    }
  }
  return 0;
}
