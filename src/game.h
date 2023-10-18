#ifndef GAME_H
#define GAME_H

#include <stdint.h>

enum GameState{
  G_Keep, G_Draw,
  G_Victory
};

enum PlayerType {
  Human, Ai
};

struct Game {
  uint16_t p1;
  uint16_t p2;
  uint8_t turn;
};

#endif // !GAME_H
