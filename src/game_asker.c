#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "game_asker.h"
#include "player.h"
#include "search.h"
#include "board_info.h"

int player_asker(int player_id, int* board, int depth) {
  char input[100]; 
  char* endptr; 

  int targetPos = 0;
  int x = -1;
  int y = -1;

  while(x<0 || x>2 || y<0 || y>2 || board[targetPos] != PLAYER_N) {
    printf("\nPlayer%d ┌──────────── Row: ", player_id);
    scanf("%s", input);
    strtol(input, &endptr, 10);
    printf("────────┤\n        └───────── Column: ");

    if (*endptr == '\0') { //Valid number
      x = atoi(input);
    } else { // Not a number
      printf("-\n");
      continue;
    }

    scanf("%s", input);
    strtol(input, &endptr, 10);

    if (*endptr == '\0') { //Valid number
      y = atoi(input);
    } else { // Not a number
      continue;
    }

    fflush(stdin);
    targetPos = x*3+y; 
  }
  return targetPos;
}

int ai_asker(int player_id, int* board, int depth) {
  int pmax = player_id;
  int pmin = (pmax == PLAYER_2)? PLAYER_1 : PLAYER_2; 
  int best_score = INT_MIN;
  int score = 0, aux = 0;
  int move = -1;

  for (int i = 0; i < BOARD_LEN; i++) {
    if(board[i] == PLAYER_N) {
      board[i] = pmax;
      score = alphabeta(board, 0, pmax, pmin, 1, 
                        (depth > 9 || depth < 1)? 9 : depth, INT_MIN, INT_MAX);
      board[i] = PLAYER_N;

      if(score > best_score) {
        best_score = score;
        move = i;
      }
      aux = i;
    }
  }
  return (move == -1)? aux : move;
}
