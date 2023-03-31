#include "../constants.h"
#include "../utils.h"

int player_asker(int player_id, int* board) {
  int targetPos = readCoordinates(player_id);
  
  while (board[targetPos] != PLAYER_N) {
    targetPos = readCoordinates(player_id);
  }
  return targetPos;
}
