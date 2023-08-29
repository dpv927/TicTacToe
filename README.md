# Tic-tac-toe (ttt)

## Features

- Only for Linux!
- No dependencies
- Best move finder
- Multiplayer game
    - PLayers turns syncronization with API Systemm V
    - Linux API System V Semaphores
    - Linux API System V Shared Memory
- Blazingly fast AI
- Easy to understand documentation

## About
This application is dedicated to playing games between humans and machines. The available options in the application are:

`--player-mode`: Play against another human or play with yourself.<br>
`--ai-mode`: Play against the machine.<br>
`--max-depth`: Specify the maximum depth of the AI's search tree.<br>
`--help`: Show the help file.<br>
`--version`: Show the current version of ttt.<br>
`--search`: Search the best move for a player given a game state. <br>

## Compiling ttt
The compilation process is only available on Linux due to the use of System V semaphores and shared memory API. A custom makefile has been created, and you can compile the program using the following command:

```bash
cd tic-tac-toe
make clean all # Alternatively, use 'make clean-build'
```
> **Note**
> If wou want to modify any value or see more compilation commands, just check the makefile or the file named 'makefile_opts.txt' at tic-tac-toe/src/about/. This files are well documented, so everything should be very easy to understand to a basic C or Linux user.

If you want to do a quick check to the Make options, you can use the next command;
```bash
make help
```

## License
The entire ttt project is licensed under the [GNU General Public License v2.0](License). Please make sure to read the requirements before making any changes to this project.
