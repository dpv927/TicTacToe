#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "board.h"
#define SEMKEY 200
#define SEM_NUM 2
#define SEM0 0
#define SEM1 1

int readCoordinates(int id);
int fork();

int main() {
  int x;
  int y;
  int tmp;
  int semid;
  int shmid;
  int status;
  int game_eval;
  int process_id;
  struct sembuf sem_oper;
 
  struct data {
    int arr[9];
  }*addr, used;

  union semun {
    int val;
    struct semid_ds *semstat;
    unsigned short *array;
  } arg;
 
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

  switch(fork()) {
    case -1: 
      exit(-1);
    break;

    case 0:
      process_id = PLAYER_1;
      addr[0] = used;

      while(true) {
        sem_oper.sem_num = SEM0;
        sem_oper.sem_op = -1;
        semop(semid, &sem_oper, 1);
        
        game_eval = evaluateGame(addr[0].arr);
        if(boardIsFull(addr[0].arr) || game_eval != -2) {
          break;
        }        

        printf("\nAfter the last move, the board state is:\n");
        printGame(addr[0].arr);        

        tmp = readCoordinates(PLAYER_1);
        while(addr[0].arr[tmp]!=0) {
          tmp = readCoordinates(PLAYER_1);
        }
        addr[0].arr[tmp] = PLAYER_1;

        sem_oper.sem_num = SEM1;
        sem_oper.sem_op = 1;
        semop(semid, &sem_oper, 1);
      }
    break;

    default:
      process_id = PLAYER_2;

      while(true) {
        sem_oper.sem_num = SEM1;
        sem_oper.sem_op = -1;
        semop(semid, &sem_oper, 1);

        game_eval = evaluateGame(addr[0].arr);
        if(boardIsFull(addr[0].arr) || game_eval != -2) {
          break;
        }

        printf("\nAfter the last move, the board state is:\n");
        printGame(addr[0].arr);
        
        tmp = readCoordinates(PLAYER_2);
        while(addr[0].arr[tmp]!=0) {
          tmp = readCoordinates(PLAYER_2);
        }
        addr[0].arr[tmp] = PLAYER_2;

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
      case 1: printf("Player1 wins! :)\n");
      break;
      case -1: printf("Player2 wins! :)\n");
      break;
      case 0: printf("Its a draw! :O\n");
    }
  }

  semctl(semid, SEM_NUM, IPC_RMID, 0);
  free(arg.array);
  shmdt(addr);
  shmctl(shmid, IPC_RMID, 0);
  return 0; 
}

/**@brief Reads the coordinates of the next move in
 * a game**/
int readCoordinates(int id) {
  int x = -1;
  int y = -1;

  while(x<0 || x>2 || y<0 || y>2) {
    printf("\nPlayer%d ┌──────────── Row: ", id);
    scanf("%d", &x);
    printf("────────┤\n        └───────── Column: ");
    scanf("%d", &y);
    fflush(stdin);
  }
  return x*3+y;
}
