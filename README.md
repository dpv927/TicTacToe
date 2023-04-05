<!-- 
  Badges div/container. In this div you will find the title of this repo, the logo,
  a simple description and the badges of the repo.

  With the badges we can show in more detail the activity in the repo, the license
  and other details. The badges are imported as images, wich links are located at
  the bottom of this documnent. See img.shields.io for more info.
 -->
<div align="center">
  <h3>Tic-Tac-Toe</h3> 
  <img src="readme/ttt-logo.png" width="150">
  
  A simple and strong Tic-Tac-Toe app<br>
  ***Designed for Linux***.
  <br>
  <br>
  
  [![License][license-badge]][license-link] <!-- License of this repo -->
  <br>
  [![Release][release-badge]][release-link] <!-- latest release -->
  [![Commits][commits-badge]][commits-link] <!-- Commits since last release -->
</div>

<!--
  About section: In this section we describe how ttt is done and some of 
  its history.
-->
## About
Tic Tac Toe is a very famous board game, and it is very easy to implement in code. Because of this, I wanted to make it a bit more challenging without changing the basic concepts of the game. To achieve this, I implemented the game using the `API System 5` Semaphores and shared memory of Linux to manage both players' turns and the board control, and some more features like an AI.

<!--
  How to use section: How ttt works? How to work with ttt?
-->
## How to Use
The game prompts the players for the coordinates of their next move. First, it asks for the row, and then the column. Let's say that a coordinate is made up of (row, column). The board display is as follows:
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

<!--
Modes section: Here we explain the different modes that the application
has (1vs1, person vs AI...)
-->
## Modes
With the current version of `ttt v2.0.0`, you can play the famous game with another person or by yourself in the same terminal, automatically switching turns so both players can participate. You can also play with an AI that uses minimax, that seeks for its best move. Lets see both options:
```bash
ttt --player-mode # Play a 1vs1 game
ttt --ai-mode     # Play against the AI
```

<!--
  Compile section: How can the user compile the project if the source code is
  changed, or other arquitecture is necessary.
-->
## Compile
To compile and manage all the files of the project, the `Makefile` script has been created. This script can be passed different instructions as parameters, which it will check and execute on the project. Let's see some examples:
```bash
make clean # Cleans all the .o files and the old executable
make # Compiles the project
```

<!--
Like we said at the top of the document, near the title and badges, here we define
some of the links that we use in this file.
-->
[license-link]:       https://github.com/dpv927/tic-tac-toe/blob/main/LICENSE
[release-link]:       https://github.com/dpv927/tic-tac-toe/releases/tag/1.0.0
[commits-link]:       https://github.com/dpv927/tic-tac-toe

[commits-badge]:      https://img.shields.io/github/commits-since/dpv927/tic-tac-toe/latest?style=for-the-badge&color=f5f5f5
[license-badge]:      https://img.shields.io/github/license/dpv927/tic-tac-toe?style=for-the-badge&label=license&color=fbe09f
[release-badge]:      https://img.shields.io/github/v/release/dpv927/tic-tac-toe?style=for-the-badge&label=official%20release&color=f5f5f5

<!--
  Next Updates:
    - Add the new modes of the application.
    - Add new help at the "How to use" section.
    - Add new commands at the compile section.
-->
