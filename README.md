<div class="languages" align="center">

# Tic-Tac-Toe

:uk: <a href="#">English</a>
:es: <a href="https://github.com/dpv927/tic-tac-toe/blob/main/READMEes.md">Español</a>
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

## Compile
To compile and manage all the files of the project, the `Makefile` script has been created. This script can be passed different instructions as parameters, which it will check and execute on the project. Let's see some examples:
```bash
make clean # Cleans all the .o files and the old executable
make # Compiles the project
```

## Structure
```
tic-tac-toe/
├── CONTRIBUTORS
├── doc
│   ├── help.txt
│   └── version.txt
├── LICENSE
├── READMEes.md
├── README.md
├── src
│   ├── board.c
│   ├── board.h
│   ├── constants.h
│   ├── dependencies.txt
│   ├── main.c
│   ├── Makefile
│   ├── resources.c
│   ├── resources.h
│   ├── search.c
│   ├── search.h
│   ├── utils.c
│   └── utils.h
└── tic-tac-toe.6

3 directories, 19 files
```
