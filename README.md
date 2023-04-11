## Tic-tac-toe (ttt)

### Features
- No dependencies
- Multiplayer game (Only for Linux)
    - Linux API System 5 Semaphores
    - Linux API System 5 Shared Memory

### Ttt-play
As mentioned before, this application is dedicated to playing games between humans and machines. The available options in the application are:

- `--player-mode`: Play against another human or with yourself.
- `--ai-mode`: Play against the machine.
- `--help`:  Show the help file.
- `--version`: Show the current version of ttt-play.

### Compiling ttt-play
The compilation process is only available on Linux due to the use of the System V semaphores and shared memory API. A custom makefile has been created, and you can compile the program using the following command:

```bash
cd ttt-play
make clean all # Alternatively, use 'make clean-build'
```

### License
The entire ttt project, including both ttt-play and ttt-search, is licensed under the [GNU General Public License v2.0](LICENSE). Please make sure that you read the requirements before making any changes to this project.
