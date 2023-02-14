/* El tablero sera representado por una matriz 3x3, ya que es la manera mas intuitiva 
 * de representar el tablero en este problema. Este tendra unas operaciones asociadas
 * como lo son los movimientos y las comprobaciones para ver si algun jugardor ha
 * ganado, hay empate o nanguna de las anteriores. */
int board[] = {
  0,0,0,
  0,0,0,
  0,0,0
};

int isFull() {
  for (int i=0; i<9; i++)
	  if (board[i] == 0)
		  return 0;
	return 1;
}

void makeMove(int pos, int val) {
  board[pos] = val;
}

int evaluateInStep(int start, int step) {
 int pre_owner, end = start + step;

  for (int i = start; i <= end; i += step) {
			pre_owner = board[i-step];
			if (pre_owner == 0 || board[i] != pre_owner)
				return 0;
			if (i == end)
				return (pre_owner == -1)? 1 : -1;
		}
		return 0;
}

int evaluateGame() {
  // Diagonal left up - right down
		int result = evaluateInStep(4, 4);
		if (result != 0)
			return result;

		// Diagonal right up - left down
		result = evaluateInStep(4, 2);
		if (result != 0)
			return result;

		// All the rows
		for (int i = 1; i <= 7; i += 3) {
			result = evaluateInStep(i, 1);
			if (result != 0)
				return result;
		}

		// All the columns
		for (int i = 3; i <= 5; i += 1) {
			result = evaluateInStep(i, 3);
			if (result != 0)
				return result;
		}
		return (isFull()==1)? 0 : -2;
}
