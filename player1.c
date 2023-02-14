#include <stdio.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdbool.h>
#include "board.h"
#define KEY 100
#define END 8
#define sem_pl1 0
#define sem_pl2 1
#define sem_eng 2

int main() {
  int semid;
  int shmid;
  int board_pos;
  struct sembuf sem_oper;

  union semun {
    int val; 
    struct semid_ds *semstat;
    unsigned short *array;
  } arg;

  struct data {
    int position;
    int value;
  } *addr, move;

  semid = semget(KEY, 3, IPC_CREAT | 0700);
  if(semid == -1) {
    printf("Error accessing or creating the semaphores.\n");
    exit(-1);
  }

  shmid = shmget(KEY, sizeof(int) * 2, IPC_CREAT | 0700);
  if(semid == -1) {
    printf("Error accessing or creating the shared memory.\n");
    exit(-1);
  }

  addr = shmat(shmid, 0, 0);
  sem_oper.sem_flg = SEM_UNDO;
  move.value = 1;

  while(true) {
    // Wait al sem player 1
    sem_oper.sem_num = sem_pl1;
    sem_oper.sem_op = -1;
    semop(semid, &sem_oper, 1);
    
    if(addr[0].value == END) {
      exit(0);
    }

    // Get info
    printf("Write the desired position of your move [0-8]: ");
    scanf("%d", &board_pos);
    move.position = board_pos;
    addr[0] = move;

    printf("lolool\n");

    //Signal sem_eng
    sem_oper.sem_num = sem_eng;
    sem_oper.sem_op = 1;
    semop(semid, &sem_oper, 1);
  }
  return 0;
}
