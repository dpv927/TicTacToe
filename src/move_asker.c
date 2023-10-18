#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "move_asker.h"
#include "search.h"
#include "game.h"
#include "bits.h"

uint8_t player_asker(const int pid, struct Game* g){
  uint16_t state = g->p1|g->p2;
  uint8_t targetPos = 0;
  int x = -1, y = -1;
  char input[100]; 
  char* endptr;
  
  while(x<0 || x>2 || y<0 || y>2 || getBit(state, targetPos)) {
    printf("\nPlayer%d ┌──────────── Row: ", pid);
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
    } else continue;
    targetPos = x*3+y; 
  }
  return targetPos;
}

uint8_t ai_asker(uint16_t pmaxBoard, uint16_t pminBoard, uint8_t depth) {
  uint16_t state = pmaxBoard|pminBoard;
  int best_score = INT_MIN;
  int score, move = 0;  

 for (int i = 0; i < 9; i++) {
    if(!getBit(state,i)) {

      setbit(pmaxBoard, i);
      score = alphabeta(0, pmaxBoard, pminBoard, 1, depth, INT_MIN, INT_MAX);    
      setZeroBit(pmaxBoard, i);
      
      if(score > best_score) {
        best_score = score;
        move = i;
      }
    }
  }
  return move;
}
