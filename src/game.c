#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <fcntl.h>
#include "game.h"
#include "board.h"
#include "board_info.h"
#include "game_asker.h"
#include "player.h"
#define SEMKEY 175
#define SEM_NUM 2
#define SEM0 0
#define SEM1 1

/* global variables definition */
int semid;
int shmid;
int process_id;

union semun {
    int val;
    struct semid_ds *semstat;
    unsigned short *array;
} arg;

struct Game game;
struct Game* addr;
/* global variables definition */

void start_game(const int mode, const int maxAidepth) {
  int join;
  enum GameState g_state;
  struct sembuf sem_oper;

  // Create signal handlers (Ctrl+c, kill...)
  signal(SIGINT, sigint_handler);
  signal(SIGTERM, sigterm_handler);
 
  // Try to Create the semaphores
  semid = semget(SEMKEY, SEM_NUM, IPC_CREAT | 0700);
  if(semid == -1) { exit(-1); }

  // Initialize all the semaphores. The created semaphores will work
  // as binary semaphores.
  arg.array = (unsigned short *) malloc(sizeof(short) * SEM_NUM);
  arg.array[SEM0] = 1;
  arg.array[SEM1] = 0;
  semctl(semid, SEM_NUM, SETALL, arg);
  sem_oper.sem_flg = SEM_UNDO;

  // Create the shared memory
  shmid = shmget(SEMKEY, sizeof(struct Game), IPC_CREAT | 0700);
  if (shmid == -1) { exit(-1); }
  addr = shmat(shmid, 0, 0);

  // Create the players. Player1 is human by default, Player2 can be 
  // changed with the arguments that are passed to the program.
  struct Player p1 = {
    Human,
    DEF_P1_REP,
    PLAYER_1
  };

  struct Player p2 = {
    (mode)? Human : Ai,
    DEF_P2_REP,
    PLAYER_2
  };
  
  // Initialize the board and game
  game.t_index = 1;
  game.players[0] = p1;
  game.players[1] = p2;

  // With fork we create two separated processes. Those processes
  // are used to manage the players turns.
  switch(fork()) {
    case -1: 
      exit(1);
    break;

    case 0:
      // Player1 process (child) - Its the first to move
      addr[0] = game;

      while(1) {
        // Do a WAIT to the semaphore0
        sem_oper.sem_num = SEM0;
        sem_oper.sem_op = -1;
        semop(semid, &sem_oper, 1);
        
        // Get the actual evaluation of the game and check if the
        // game is over (Anything else than G_Keep).
        g_state = evaluateGame(addr[0].board);
        if(g_state != G_Keep) { 
          // Do a SIGNAL to semaphore1
          sem_oper.sem_num = SEM1;
          sem_oper.sem_op = 1;
          semop(semid, &sem_oper, 1);  
          break; 
        }        
        
        system("clear");
        printf("The actual board state is:\n\n");
        printBoard(addr[0]);
      
        // Ask player1 the next move and apply it
        int pos = player_asker(p1.id, addr[0].board);
        addr[0].board[pos] = p1.id;
        addr[0].t_index ^= 1;
        
        // Do a SIGNAL to semaphore1
        sem_oper.sem_num = SEM1;
        sem_oper.sem_op = 1;
        semop(semid, &sem_oper, 1);
      }
    break;

    default:
      while(1) {
        // Make a WAIT to semaphore1
        sem_oper.sem_num = SEM1;
        sem_oper.sem_op = -1;
        semop(semid, &sem_oper, 1);

        // Get the actual evaluation of the game and check if the
        // game is over (Anything else than G_Keep). 
        g_state = evaluateGame(addr[0].board);
        if(g_state != G_Keep) {
          // Make a SIGNAL to semaphore0 
          sem_oper.sem_num = SEM0;
          sem_oper.sem_op = 1;
          semop(semid, &sem_oper, 1);
          break; 
        }
        
        system("clear");
        printf("The actual board state is:\n\n");
        printBoard(addr[0]);

        // Ask player2 the next move and apply it 
        int pos = (mode)? player_asker(p2.id, addr[0].board)
          : ai_asker(p2.id, addr[0].board, maxAidepth);

        addr[0].board[pos] = p2.id;
        addr[0].t_index ^= 1;
        
        // Make a SIGNAL to semaphore0 
        sem_oper.sem_num = SEM0;
        sem_oper.sem_op = 1;
        semop(semid, &sem_oper, 1);
      }

      // Finish the game 
      system("clear");
      printf("The final board state is:\n");
      printBoard(addr[0]);
   
      if(g_state == G_Draw)
        printf("There was a draw!");
      else  printf("Player%d won!", (addr[0].t_index)+1);
      
      // Delete the game resources and wait to both 
      // processes to finish
      delete_resources();
      wait(&join);
    break;
  }
}

void sigint_handler(const int signum) {
    delete_resources();
    exit(signum);
}

void sigterm_handler(const int signum) {
    delete_resources();
    exit(signum);
}

void delete_resources(void) {
  semctl(semid, SEM_NUM, IPC_RMID, 0);
  free(arg.array);
  shmdt(addr);
  shmctl(shmid, IPC_RMID, 0);
}
