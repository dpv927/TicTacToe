#include "heuristic.h"
#include "board.h"

int heuristic(int* board, const int bias) {
  	// Diagonal left up - right down
		int result = heuristicInStep(4, 4, board, bias);
		if (result != EVAL_KEEP)
			return result;

		// Diagonal right up - left down
		result = heuristicInStep(4, 2, board, bias);
		if (result != EVAL_KEEP)
			return result;

		// All the rows
		for (int i = 1; i <= 7; i += 3) {
			result = heuristicInStep(i, 1, board, bias);
			if (result != EVAL_KEEP)
				return result;
		}

		// All the columns
		for (int i = 3; i <= 5; i += 1) {
			result = heuristicInStep(i, 3, board, bias);
			if (result != EVAL_KEEP)
				return result;
		}
		return (boardIsFull(board))? NO_EVAL : result;
}

int heuristicInStep(const int start, const int step, int* board, const int bias) {
 int pre_owner = 0;

  for (int i = start; i <= start + step; i += step) {
			pre_owner = board[i-step];
			if (pre_owner == PLAYER_N || board[i] != pre_owner)
				return EVAL_KEEP;
		}
		return (pre_owner == bias)? MAX_EVAL : MIN_EVAL;
}
