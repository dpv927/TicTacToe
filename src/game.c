#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include "constants.h"
#include "board.h"
#include "game-asker.h"
#include "game.h"
#define SEMKEY 185
#define SEM_NUM 2
#define SEM0 0
#define SEM1 1

int semid;
int shmid;
int process_id;

union semun {
    int val;
    struct semid_ds *semstat;
    unsigned short *array;
} arg;

struct data {
    int arr[9];
}*addr, used;

void start_game(int mode) {
  int game_eval;
  struct sembuf sem_oper;
  int (*asker_plr1)(int, int*);
  int (*asker_plr2)(int, int*);

  signal(SIGINT, sigint_handler);
  signal(SIGTERM, sigterm_handler);
 
  semid = semget(SEMKEY, SEM_NUM, IPC_CREAT | 0700);
  if(semid == -1) { exit(-1); }

  arg.array = (unsigned short *) malloc(sizeof(short) * SEM_NUM);
  arg.array[SEM0] = 1;
  arg.array[SEM1] = 0;
  semctl(semid, SEM_NUM, SETALL, arg);
  sem_oper.sem_flg = SEM_UNDO;

  shmid = shmget(SEMKEY, sizeof(int)*BOARD_LEN, IPC_CREAT | 0700);
  if (shmid == -1) { exit(-1); }
  addr = shmat(shmid, 0, 0);
  
  if(mode) {
    asker_plr1 = &player_asker;
    asker_plr2 = &player_asker;
  }else {
    asker_plr1 = &player_asker;
    asker_plr2 = &ai_asker;
  }

  switch(fork()) {
    case -1: 
      exit(-1);
    break;

    case 0:
      process_id = PLAYER_1;
      addr[0] = used;
      
      printf("New game just started...");

      while(1) {
        sem_oper.sem_num = SEM0;
        sem_oper.sem_op = -1;
        semop(semid, &sem_oper, 1);
        
        game_eval = evaluateGame(addr[0].arr);
        if(boardIsFull(addr[0].arr) || game_eval != COND_KEEP) {
          break;
        }        
        
        system("clear");
        printf("\nThe actual board state is:\n");
        printGame(addr[0].arr);
        
        int pos = (*asker_plr1)(PLAYER_1, addr[0].arr);
        addr[0].arr[pos] = PLAYER_1;

        sem_oper.sem_num = SEM1;
        sem_oper.sem_op = 1;
        semop(semid, &sem_oper, 1);
      }
    break;

    default:
      process_id = PLAYER_2;

      while(1) {
        sem_oper.sem_num = SEM1;
        sem_oper.sem_op = -1;
        semop(semid, &sem_oper, 1);

        game_eval = evaluateGame(addr[0].arr);
        if(boardIsFull(addr[0].arr) || game_eval != COND_KEEP) {
          break;
        }
        
        system("clear");
        printf("\nThe actual board state is:\n");
        printGame(addr[0].arr);

        int pos = (*asker_plr2)(PLAYER_2, addr[0].arr);
        addr[0].arr[pos] = PLAYER_2;

        sem_oper.sem_num = SEM0;
        sem_oper.sem_op = 1;
        semop(semid, &sem_oper, 1);
      }
    break;
  }

  if(process_id == PLAYER_1) {
    printf("\nAfter the last move, the board state is:\n");
    printGame(addr[0].arr);

    switch (game_eval) {
      case PLAYER_1: printf("Player1 wins! :)\n\n");  break;
      case PLAYER_2: printf("Player2 wins! :)\n\n");  break;
      case COND_DRAW: printf("Its a draw! :O\n\n");   break;
    }
  }
  delete_resources();
}

void printGame(int board[]) {
  printf("┌───┬───┬───┐\n");

  for (int i = 0; i < BOARD_LEN; i++) {
    printf("│ %c ", (board[i] == PLAYER_1)? 'x' : ((board[i] == PLAYER_2)? 'o' : ' '));
    
    if (i == 2 || i == 5) 
      printf("│\n├───┼───┼───┤\n");
  }

  printf("│\n└───┴───┴───┘\n");
}

void delete_resources() {
  semctl(semid, SEM_NUM, IPC_RMID, 0);
  free(arg.array);
  shmdt(addr);
  shmctl(shmid, IPC_RMID, 0);
}

void sigint_handler(int signum) {
    if(process_id == PLAYER_2) return;
    delete_resources();
    exit(signum);
}

void sigterm_handler(int signum) {
    if(process_id == PLAYER_2) return;
    delete_resources();
    exit(signum);
}
