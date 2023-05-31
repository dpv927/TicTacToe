#include "heuristic.h"
#include "board.h"

int heuristicInStep(int* board, int start, int step, int end, int bias) {
  int max_counter = 0;
  int min_counter = 0;

  for (int i = start; i <= end; i += step) {
    int val = board[i];
    if(val == bias) { max_counter++; }
    else if (val != PLAYER_N) { min_counter++; }
  }
  if(max_counter == 3) { 
    return MAX_EVAL; 
  } else if(min_counter == 3) { return MIN_EVAL; };
  return max_counter * Pscores[max_counter] + min_counter * Pscores[min_counter];
}

int heuristic(int *board, int bias) {
  if(boardIsFull(board)) return NO_EVAL;

  int sum = 0;
  int score;

  // Diagonal left up - right down
  score = heuristicInStep(board, 0, 4, 8, bias);
  if (score == MAX_EVAL || score == MIN_EVAL)
			return score;
  sum += score;

	// Diagonal right up - left down
	score = heuristicInStep(board, 2, 2, 6, bias);
  if (score == MAX_EVAL || score == MIN_EVAL)
			return score;
  sum += score;

	// All the rows
	for (int i = 0; i <= 6; i += 3) {
		score = heuristicInStep(board, i, 1, i+2, bias);
		if (score == MAX_EVAL || score == MIN_EVAL)
			return score;
    sum += score;
	}

	// All the columns
	for (int i = 0; i <= 2; i ++) {
		score = heuristicInStep(board, i, 3, i+6, bias);
		if (score == MAX_EVAL || score == MIN_EVAL)
			return score;
    sum += score;
	}
  return sum + score;
}
