<div class="languages" align="center">

# Tic-Tac-Toe

:uk: <a href="#">English</a>
:es: <a href="https://github.com/dpv927/tic-tac-toe/blob/main/esREADME.md">Español</a>
</div>

## About
Tic tac toe its a very famous board game, and very easy to implement in code. Because of that, I wanted to do it a bit harder but without changing the basic concepts of the game. To do so, I implemented the game with the `API System 5` semaphores and shared memory of Linux, just to manage both players turns in the game and the board control.

## How to use
The game asks both players for a coordinate of their next move. First, it asks for the row and then the column. Lets say that a coordinate is made up with (row, column), so we have the next board display:
```
+-------+-------+-------+
| (0,0) | (0,1) | (0,2) |
+-------+-------+-------+ This is how the game understands the game board
| (1,0) | (1,1) | (1,2) | coordinates
+-------+-------+-------+
| (2,0) | (1,1) | (2,2) |
+-------+-------+-------+
```
Lets see an example:
```
+---+---+---+
| x |   |   |
+---+---+---+   We can see that the 'x' player made a move on
|   |   |   |   (0,0) and the 'o' player did on (2,1)
+---+---+---+
|   | o |   |
+---+---+---+
```
In the game, the `player1` is represented with `x` and `player2` with `o`.
`
## Compile & Install
The project has an easy way to compile all the source code to an executable file and install it. To compile run:
```bash
./build.sh
```
Explicar las demas funcionalidades de build.sh

## Uninstall
To unistall the program, just remove the executable at the source path:
```bash
sudo rm /usr/bin/eightgame
```
