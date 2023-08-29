#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include "analysis.h"
#include "player.h"
#include "board_info.h"
#include "search.h"
#include "board.h"

void search(const char* gstate, const int depth) {
  // Initialize game propierties
  struct Player p1 = { NULL, Ai, DEF_P1_REP, PLAYER_1 };
  struct Player p2 = { NULL, Ai, DEF_P2_REP, PLAYER_2 };

  struct Game sgame;
  sgame.players[0] = p1;
  sgame.players[1] = p2;
  initGameState(gstate, &sgame);

  // Start the search
  int best_score = INT_MIN, score = 0, move = -1;
  int pmax = (sgame.players[sgame.t_index]).id;
  int pmin = (pmax == PLAYER_1)? PLAYER_2 : PLAYER_1;

  printf("Searching the best move at '%s'. Player to maximize: player%d ('%c').\n", gstate, pmax, 
         sgame.players[sgame.t_index].pl_rep);
  printf("The search is limited to %d nodes deep in the search tree.\nGiven game representation:\n", depth);
  printBoard(sgame);

  // Start timer
  clock_t begin = clock();

  for (int i = 0; i < BOARD_LEN; i++) {
    if(sgame.board[i] == PLAYER_N) {
      sgame.board[i] = pmax;
      score = alphabeta(sgame.board, 0, pmax, pmin, 1, 
                        (depth > 9 || depth < 1)? 9 : depth, INT_MIN, INT_MAX);
      sgame.board[i] = PLAYER_N;

      if(score > best_score) {
        fflush(stdout);
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
    printf("Not eleven!");
    exit(1);
  }
  
  for (int i = 0; i < 9; i++) {
    switch (gstate[i]) {
      case '-': gstruct->board[i] = PLAYER_N; break;
      case '1': gstruct->board[i] = PLAYER_1; break;
      case '2': gstruct->board[i] = PLAYER_2; break;
      default: printf("Not a char '%c'", gstate[i]); exit(1);
    }
  }
  
  // Get player to maximize (Its the player that has the actual turn
  // in the game and has to win). 
  char* endptr;
  strtol(&gstate[10], &endptr, 10);

  if(*endptr == '\0') {
    switch (gstate[10]) {
      case '1': gstruct->t_index = 0; break;
      case '2': gstruct->t_index = 1; break;
      default: printf("Not a number '%c'", gstate[10]); exit(1);
    }
  }
}
