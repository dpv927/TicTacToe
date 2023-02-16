#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#define SEMKEY 100
#define SEM_NUM 2
#define SEM0 0
#define SEM1 1

int main() {
  int cont;
  int pos;
  int semid;
  int shmid;
  int status;
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
    case 1:
      cont = 0;
      while(cont<5) {
        sem_oper.sem_num = SEM0;
        sem_oper.sem_op = -1;
        sem_oper.sem_flg = SEM_UNDO;
        semop(semid, &sem_oper, 1);

        printf("1: Write a number: ");
        scanf("%d", &pos);
        cont++;
      
        sem_oper.sem_num = SEM1;
        sem_oper.sem_op = 1;
        sem_oper.sem_flg = SEM_UNDO;
        semop(semid, &sem_oper, 1);
      }
    break;

    case 0:
      cont = 0;
      while(cont<5) {
        sem_oper.sem_num = SEM1;
        sem_oper.sem_op = -1;
        sem_oper.sem_flg = SEM_UNDO;
        semop(semid, &sem_oper, 1);

        printf("2: Write a number: ");
        scanf("%d", &pos);
        cont++;
      
        sem_oper.sem_num = SEM0;
        sem_oper.sem_op = 1;
        sem_oper.sem_flg = SEM_UNDO;
        semop(semid, &sem_oper, 1);
      }
    break;
    
    default:
      printf("Error when forking the process. EXiting...\n");
      exit(-1);
    break;
  }

  wait(&status);
  semctl(semid, SEM_NUM, IPC_RMID, 0);
  return 0; 
}
