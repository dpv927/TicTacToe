#include <stdint.h>
#include "heuristic.h"

int heuristic(uint16_t pmax, uint16_t pmin) {
  uint16_t shift;
 
  /* See if some player won in rows */ 
  for (uint8_t i=0; i<=6; i+=3) {
    shift = (0x7<<i);
    if((pmax&shift) == shift)
      return MAX_EVAL;
    if((pmin&shift) == shift)
      return MIN_EVAL;
  }

  /* See if some player won in columns */ 
  for (uint8_t i=0; i<=2; i++) {
    shift = (0x49<<i);
    if((pmax&shift) == shift)
      return MAX_EVAL;
    if((pmin&shift) == shift)
      return MIN_EVAL;
     
  }
  
  /* See if some player won in the diagonals. The constant 0x111
   * represents the '\' diagonal and the 0x54 constant represents
   * the '/' diagonal. */
  if((pmax&0x111) == 0x111 || (pmax&0x54) == 0x54)
    return MAX_EVAL;
  if((pmin&0x111) == 0x111 || (pmin&0x54) == 0x54)
    return MIN_EVAL;
  
  /* Board is full -> Draw. Else keep playing */
  return ((pmin|pmax) == 0x1ff)? NO_EVAL
    : EVAL_KEEP;
}
