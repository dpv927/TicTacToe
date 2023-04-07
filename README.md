## Tic-tac-toe (ttt)

### Features
- No dependencies
- Fast as hell
- Works in all the systems
- Multiplayer game included (Only for Linux)
    - Linux API System 5 Semaphores
    - Linux API System 5 Shared Memory

### Usage
Ttt is a really easy-to-use application, as it uses quite intuitive and simple parameters. You should know that
both the multiplayer and search modes have parameters (the latter obviously having many more). The multiplayer 
application is named ttt-play and the search application is named ttt-search. These two are very different from
each other, as the first one is solely dedicated to the game modes between human-human and human-machine, while
the second application is dedicated to searching for game moves and statistics.

### Ttt-play
As mentioned before, this is an application dedicated to playing games between people or machines. Knowing this,
we must introduce the existing options in the application:

- `--player-mode`: Play against another person or with yourself.
- `--ai-mode`: Play against the machine.
- `--depth=<depth>`: Limit the depth to a certain number. It must be in the range [0-9].
- `--help`: Show the help file.
- `--version`: Show the current version of ttt-play.

### Compiling ttt-play
The compiling process is only available at Linux because of the use of the API System 5 semaphores and shared memory.
I made a custom makefile, so you can do it like this:
```bash
cd ttt-play
make clean all # alternatively: make clean-build
```

### Ttt-search
As mentioned before, this application is dedicated to searching for game moves and statistics. Knowing this, we must
introduce the existing options in the application:

- `--game=[, , ,...]`: Specify a game board in an 'array' notation. Player1 must be '1', Player2 '2' and none '0'.
- `--depth=<depth>`: Limit the depth to a certain number. It must be in the range [0-9].
- `--algorithm=<name>`: Specify the search algorithm to use in the search.
- `--best=<bool>`: Specify if the move to search is the best or worse. Options= true, false.
- `--help`: Show the help file.
- `--version`: Show the current version of ttt-play.

### Compiling ttt-search
The compiling process is available at every system.I made a custom makefile, so you can do it like this:
```bash
cd ttt-search
make clean all # alternatively: make clean-build
```

### License
The entire ttt project (ttt-play and ttt-search) are under the [GNU General Public License v2.0](LICENSE). Be shure that you
read the requisites before doing any changes to this project.
