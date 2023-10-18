#include <sys/shm.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "game.h"
#include "board.h"
#include "move_asker.h"
#include "bits.h"
#include "sync_game.h"
#define SEMKEY 175
#define SEM_NUM 2
#define SEM0 0
#define SEM1 1

/* ---------------------------
 * global variables definition
 * --------------------------- */
int semid;
int shmid;

union semun {
  int val;
  struct semid_ds *semstat;
  unsigned short *array;
} arg;

struct Game* addr;
/* ---------------------------
 * global variables definition
 * --------------------------- */

void syncronized_game(enum PlayerType p1_mode, enum PlayerType p2_mode, uint8_t maxAidepth1, uint8_t maxAidepth2) {
  enum GameState g_state;
  struct sembuf sem_oper;
  struct Game game;
  struct Game* addr;
  int join;

  union Semun {
    int val;
    struct semid_ds *semstat;
    unsigned short *array;
  } arg;

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

  // Create the game object
  game.p1 = 0x0;
  game.p2 = 0x0;
  game.turn = 0x1;

  // With fork we create two separated processes. Those processes
  // are used to manage the players turns.
  switch(fork()) {
    case -1: 
      exit(1);
    break;

    case 0:
      // Player1 process (child) - 
      // Its the first to move
      addr[0] = game;

      while(1) {
        // Do a WAIT to the semaphore0
        sem_oper.sem_num = SEM0;
        sem_oper.sem_op = -1;
        semop(semid, &sem_oper, 1);
        
        // Get the actual evaluation of the game and check if the
        // game is over (Anything else than G_Keep).
        g_state = evaluateGame(&addr[0]);
        if(g_state != G_Keep) { 
          // Do a SIGNAL to semaphore1
          sem_oper.sem_num = SEM1;
          sem_oper.sem_op = 1;
          semop(semid, &sem_oper, 1);  
          break; 
        }        
        
        //system("clear");
        printf("The actual board state is:\n\n");
        draw(&addr[0]);
      
        // Ask player1 the next move and apply it
        uint8_t pos = (p1_mode == Human)? player_asker(1, &addr[0])
          : ai_asker(addr[0].p1, addr[0].p2, maxAidepth1);

        setbit(addr[0].p1, pos);
        addr[0].turn ^= 1;
        
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
        g_state = evaluateGame(&addr[0]);
        if(g_state != G_Keep) {
          // Make a SIGNAL to semaphore0 
          sem_oper.sem_num = SEM0;
          sem_oper.sem_op = 1;
          semop(semid, &sem_oper, 1);
          break; 
        }
        
        //system("clear");
        printf("The actual board state is:\n\n");
        draw(&addr[0]);

        // Ask player2 the next move and apply it 
        uint8_t pos = (p2_mode == Human)? player_asker(2, &addr[0])
          : ai_asker(addr[0].p2, addr[0].p1, maxAidepth2);

        setbit(addr[0].p2, pos);
        addr[0].turn ^= 1;
        
        // Make a SIGNAL to semaphore0 
        sem_oper.sem_num = SEM0;
        sem_oper.sem_op = 1;
        semop(semid, &sem_oper, 1);
      }

      // Finish the game 
      system("clear");
      printf("The final board state is:\n");
      draw(&addr[0]);
   
      if(g_state == G_Draw)
        printf("There was a draw!");
      else  printf("Player%d won!", (addr[0].turn)+1);
      
      // Delete the game resources and wait to both 
      // processes to finish
      delete_resources();
      wait(&join);
    break;
  }
}

void delete_resources(void) {
  semctl(semid, SEM_NUM, IPC_RMID, 0);
  free(arg.array);
  shmdt(addr);
  shmctl(shmid, IPC_RMID, 0);
}

void sigint_handler(const int signum) {
    delete_resources();
    exit(signum);
}

void sigterm_handler(const int signum) {
    delete_resources();
    exit(signum);
}
