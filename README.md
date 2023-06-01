# Tic-tac-toe (ttt)

## Features

- No dependencies
- Multiplayer game (Only for Linux)
    - Linux API System V Semaphores
    - Linux API System V Shared Memory
- Blazingly fast AI
- Its made in C -> lightweight
- Easy to understand documentation

## About
This application is dedicated to playing games between humans and machines. The available options in the application are:

`--player-mode`: Play against another human or play with yourself.<br>
`--ai-mode`: Play against the machine.<br>
`--help`: Show the help file.<br>
`--version`: Show the current version of ttt-play.<br>

## Compiling ttt
The compilation process is only available on Linux due to the use of System V semaphores and shared memory API. A custom makefile has been created, and you can compile the program using the following command:

```bash
cd tic-tac-toe
make clean all # Alternatively, use 'make clean-build'
```
> **Note**
> If wou want to modify any value or see more compilation commands, just check the makefile. This file is well documented, so everything should be very easy to understand to a basic C or Linux user.

## License
The entire ttt project is licensed under the [GNU General Public License v2.0](License). Please make sure to read the requirements before making any changes to this project.
