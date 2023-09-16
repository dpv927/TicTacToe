#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "game_asker.h"
#include "player.h"
#include "search.h"
#include "board_info.h"

int player_asker(const int player_id, int* board) {
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
    targetPos = x*3+y; 
  }
  return targetPos;
}

int ai_asker(const int player_id, int* board, const int depth) {
  int best_score = INT_MIN;
  int score, move = 0;

  for (int i = 0; i < BOARD_LEN; i++) {
    if(board[i] == PLAYER_N) {

      board[i] = player_id;       /* with '^' we calculate the other player id */
      score = alphabeta(board, 0, player_id, (player_id ^ P_MASK), 1, depth, INT_MIN, INT_MAX);    
      board[i] = PLAYER_N;
      
      if(score > best_score) {
        best_score = score;
        move = i;
      }
    }
  }
  return move;
}
