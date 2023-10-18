#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "game.h"
#include "bits.h"

static const char separator[] = "  ├───┼───┼───┤\n";
static const char top[]       = "  ┌───┬───┬───┐\n";
static const char bottom[]    = "  └───┴───┴───┘\n";
static const char numbers[]   = "    0   1   2\n";

enum GameState evaluateGame(struct Game* g) {
  uint16_t shift;

  /* See if some player won in rows */ 
  for (uint8_t i=0; i<=6; i+=3) {
    shift = (0x7<<i);
    if((g->p1&shift) == shift || (g->p2&shift) == shift)
      return G_Victory;
  }

  /* See if some player won in columns */ 
  for (uint8_t i=0; i<=2; i++) {
    shift = (0x49<<i);
    if((g->p1&shift) == shift || (g->p2&shift) == shift)
      return G_Victory;
  }
  
  /* See if some player won in the diagonals. The constant 0x111
   * represents the '\' diagonal and the 0x54 constant represents
   * the '/' diagonal. */
  if((g->p1&0x111) == 0x111 || (g->p2&0x111) == 0x111 || 
    (g->p1&0x54) == 0x54 || (g->p2&0x54) == 0x54)
    return G_Victory;
  
  /* Board is full -> Draw. Else keep playing */
  return ((g->p1|g->p2) == 0x1ff)? G_Draw 
    : G_Keep;
}

void draw(struct Game* g) {
  char squares[9];

  for (uint8_t i=0; i<9; i++)
    squares[i] = getBit(g->p1,i)? 'x' : 
      (getBit(g->p2,i)? 'o' : ' ');
  
  char buff[250];
  char format[7];
  strcpy(buff, top);

  for (uint8_t i=0; i<3; i++) {
    strcat(buff, "  ");
    for (uint8_t j=0; j<3; j++) {
      sprintf(format, "│ %c ", squares[3*i+j]);
      strcat(buff, format);
    }
    sprintf(format, "│ %d\n", i);
    strcat(buff, format);
    strcat(buff, i==2? bottom : separator);
  }
  strcat(buff, numbers);
  printf("%s\n", buff);
}
