#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include "analysis.h"
#include "bits.h"
#include "search.h"
#include "board.h"

void search(const char* gstate, const int depth) {
  struct Game sgame;
  sgame.p1 = 0x0;
  sgame.p2 = 0x0;
  initGameState(gstate, &sgame);

  // Start the search
  int best_score = INT_MIN, score, move = -1;
  uint16_t pmax, pmin;

  if(sgame.turn) {
    pmax = sgame.p2;
    pmin = sgame.p1;
  } else {
    pmax = sgame.p1;
    pmin = sgame.p2;
  }

  printf("Searching the best move at '%s'. Player to maximize: player%d ('%c').\n", gstate, sgame.turn+1, 
         sgame.turn? 'o' : 'x');
  printf("The search is limited to %d nodes deep in the search tree.\nGiven game representation:\n", depth);
  draw(&sgame);

  // Start timer
  clock_t begin = clock();

  for (int i = 0; i < 9; i++) {
    if(!getBit(pmax, i)) {
      setbit(pmax, i);
      score = alphabeta(0, pmax, pmin, 1, depth, INT_MIN, INT_MAX);
      setZeroBit(pmax, i);

      if(score > best_score) {
        printf("Info: Found new best move (%d, %d)\n", (int) (i/3), i%3);
        best_score = score;
        move = i;
      }
    }
  }
  // End timer: Get search spent time
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  // Print results
  fflush(stdout);
  printf("\nTotal spent time in search: %lfs.\nInfo: Depth %d best move (%d, %d)", time_spent, depth, (int) (move/3), move%3);
}

void initGameState(const char* gstate, struct Game* gstruct) {
  /* A example of a gstate string is '1---122-- 1'.
   * See ttt --help or documentation for a more detailed example. */
  if(strlen(gstate) != 11) {
    printf("The given game string is not valid.");
    exit(1);
  }
  
  for (int i = 0; i < 9; i++) {
    switch (gstate[i]) {
      case '-': continue; break;
      case '1': setbit(gstruct->p1,i); break;
      case '2': setbit(gstruct->p2,i); break;
      default: printf("Not a game char '%c'", gstate[i]); exit(1);
    }
  }
  
  // Get player to maximize (Its the player that has the actual turn
  // in the game and has to win). 
  char* endptr;
  strtol(&gstate[10], &endptr, 10);

  if(*endptr == '\0') {
    switch (gstate[10]) {
      case '1': gstruct->turn = 0; break;
      case '2': gstruct->turn = 1; break;
      default: printf("Not a game char '%c'", gstate[10]); exit(1);
    }
  }
}
