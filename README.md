## Tic-tac-toe (ttt)

### Features
- No dependencies
- Fast as hell
- Works in all the systems
- Multiplayer game included (Only for Linux)
    - Linux API System 5 Semaphores
    - Linux API System 5 Shared Memory

### Usage
ttt is an easy-to-use application that uses intuitive and simple parameters. Both the multiplayer and search modes have parameters, with the latter having many more. The multiplayer application is called ttt-play, while the search application is called ttt-search. These two applications are very different from each other. The first one is solely dedicated to game modes between humans and machines, while the second application is dedicated to searching for game moves and statistics.

### Ttt-play
As mentioned before, this application is dedicated to playing games between humans and machines. The available options in the application are:

- `--player-mode`: Play against another human or with yourself.
- `--ai-mode`: Play against the machine.
- `--depth=<depth>`: Limit the search depth to a certain number. The depth must be in the range [0-9].
- `--help`:  Show the help file.
- `--version`: Show the current version of ttt-play.

### Compiling ttt-play
The compilation process is only available on Linux due to the use of the System V semaphores and shared memory API. A custom makefile has been created, and you can compile the program using the following command:

```bash
cd ttt-play
make clean all # Alternatively, use 'make clean-build'
```

### Ttt-search
As mentioned before, this application is dedicated to searching for game moves and statistics. The available options in the application are:ce the existing options in the application:

- `--game=[, , ,...]`: Specify a game board in an 'array' notation. Player 1 must be represented by '1', player 2 by '2', and empty spaces by '0'.
- `--depth=<depth>`: Limit the search depth to a certain number. The depth must be in the range [0-9].
- `--algorithm=<name>`: Specify the search algorithm to use in the search.
- `--best=<bool>`: Specify whether to search for the best or worst move. Options are 'true' or 'false'.
- `--help`: Show the help file.
- `--version`: Show the current version of ttt-search.

### Compiling ttt-search
The compilation process is available on all systems. A custom makefile has been created, and you can compile the program using the following command:
```bash
cd ttt-search
make clean all # Alternatively, use 'make clean-build'
```

### License
The entire ttt project, including both ttt-play and ttt-search, is licensed under the [GNU General Public License v2.0](LICENSE). Please make sure that you read the requirements before making any changes to this project.
