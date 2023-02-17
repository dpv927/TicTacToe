<div class="languages" align="center">

# Tic-Tac-Toe

:uk: <a href="#">English</a>
:es: <a href="https://github.com/dpv927/tic-tac-toe/blob/main/esREADME.md">Español</a>
</div>

## About
Tic Tac Toe is a very famous board game, and it is very easy to implement in code. Because of this, I wanted to make it a bit more challenging without changing the basic concepts of the game. To achieve this, I implemented the game using the `API System 5` Semaphores and shared memory of Linux to manage both players' turns and the board control.

## How to Use

The game prompts both players for the coordinates of their next move. First, it asks for the row, and then the column. Let's say that a coordinate is made up of (row, column). The board display is as follows:
```
+-------+-------+-------+
| (0,0) | (0,1) | (0,2) |
+-------+-------+-------+ These are the game board
| (1,0) | (1,1) | (1,2) | coordinates
+-------+-------+-------+
| (2,0) | (2,1) | (2,2) |
+-------+-------+-------+

```
Let's see an example:
```
+---+---+---+
| x |   |   |
+---+---+---+   We can see that the 'x' player made a move at
|   |   |   |   (0,0), and the 'o' player made a move at (2,1).
+---+---+---+
|   | o |   |
+---+---+---+
```
In the game, player1 is represented by `x`, and player2 is represented by `o`.

## Compile & Install
Para compilar y manejar todos los archivos del projecto, se ha creado el script `build.sh`. A este script se le pueden pasar como parámetro distintas instrucciones que comprobará y ejecutara sobre el projecto. Veamos ejemplos:
```bash
./build cleanf # Removes the old files like executables and other object files.
./build generate # Compiles and generates a executable file.
./build generate-verbose # Compiles and generates a executable file in verbose mode.
./build install # If a executable exists, then it will copied to the source path.
./build cleanf generate install # Does in the same order that is specificated all the commands already described.
./build # Cleans and generates an executable. Same as './build cleanf generate' but faster.
```
Knowing that, now you can compile and manage the project as you prefer. For exaple for a quick complilation:
```bash
./build.sh
```

## Uninstall
To unistall the program, just use the `build.sh` script:
```bash
./build uninstall
```
