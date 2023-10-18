# Tic-tac-toe (ttt)

## Features

- Only for Linux!
- No dependencies
- Best move finder
- Multiplayer game
    - Players turns syncronization with API System V
    - Linux API System V Semaphores
    - Linux API System V Shared Memory
- Blazingly fast AI
- Easy to understand documentation

## About
This application is dedicated to playing games between humans and machines. The available options in the application are:

| Argument       | Description                                                                  | 
| -------------- | ---------------------------------------------------------------------------- |
| --versus       | Create a new 1vs1 game. By default, both players are humans.                 |
| --p1-type      | Specifies the player type for 'player1' at a game created with --versus      | 
| --p2-type      | Same as --p1-type but for 'player2'                                          | 
| --depth-Ai1    | Sets the maximum depth node at the seach tree for player1 if it's type is Ai |
| --depth-Ai2    | Same as --depth-Ai1 but for player2                                          |
| --bestmove     | Searches for the best move from a given state of a game                      | 
| --search-depth | Sets the maximum depth node at the seach tree for the --bestmove mode        |
| --version      | Show installed ttt version information.                                      |
| --help         | Show an advanced guide for the parameters                                    |


## Compiling ttt
The compilation process is only available on Linux due to the use of System V semaphores and shared memory API. A custom makefile has been created, and you can compile the program using the following command:

```bash
cd tic-tac-toe/src
make clean all
```
> **Note**
> If wou want to modify any value or see more compilation commands, just check the makefile or the file named 'makefile_opts.txt' at tic-tac-toe/src/about/. This files are well documented, so everything should be very easy to understand to a basic C or Linux user.

If you want to do a quick check to the Make options, you can use the next command;
```bash
make help
```

## Installing ttt

The installation is pretty simple:
```bash
cd tic-tac-toe/src
make install
```

If you want to uninstall:
```bash
make uninstall
```

## License
The entire ttt project is licensed under the [GNU General Public License v2.0](License). Please make sure to read the requirements before making any changes to this project.
