#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#define SEMKEY 100
#define SEM_NUM 2
#define SEM0 0
#define SEM1 1

int main() {
  int semid;
  int shmid;
  struct sembuf sem_oper;
 
  union semun {
    int val;
    struct semid_ds *semstat;
    unsigned short *array;
  } arg;
 
  semid = semget(SEMKEY, SEM_NUM, IPC_CREAT | 0700);
  if(semid == -1) {
    printf("Error when creating the semaphores. Exiting...\n");
    exit(-1);
  }

  arg.array = (unsigned short *) malloc(sizeof(short) * SEM_NUM);
  arg.array[SEM0] = 1;
  arg.array[SEM1] = 0;
  semctl(semid, SEM_NUM, SETALL, arg);

  switch(fork()) {
    case 0:break;
    case 1:break;
  }
  
  semctl(semid, SEM_NUM, IPC_RMID, 0);
  return 0; 
}
