#include <stdio.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include "board.h"
#define KEY 100
#define END 8
#define sem_pl1 0
#define sem_pl2 1
#define sem_eng 2

int main() {
  
  printf("New game started. Details about the players:\nPlayer 1: x\nPlayer 2: o\n\n");
  printGame();

  int semid;
  int shmid;
  int game_eval;
  int turn;
  struct sembuf sem_oper;

  union semun {
    int val; 
    struct semid_ds *semstat;
    unsigned short *array;
  } arg;

  struct data {
    int position;
    int value;
  } *addr;

  semid = semget(KEY, 3, IPC_CREAT | 0700);
  if(semid == -1) {
    printf("Error accessing or creating the semaphores.\n");
    exit(-1);
  }

  arg.array = (unsigned short *)malloc(sizeof(short) * 2);
  arg.array[sem_pl1] = 1; // Jugador 1 inicialmente desbloqueado
  arg.array[sem_pl2] = 1; // Jugador 2 inicialmente bloqueado
  arg.array[sem_eng] = 0; // Engine inicialmente desbloqueado
  semctl(semid, 3, SETALL, arg);

  shmid = shmget(KEY, sizeof(int) * 2, IPC_CREAT | 0700);
  if(semid == -1) {
    printf("Error accessing or creating the shared memory.\n");
    exit(-1);
  } 

  addr = shmat(shmid, 0, 0);
  game_eval = -2;
  turn = 0;
  sem_oper.sem_flg = SEM_UNDO;
 
  while(game_eval == -2) {
    if(turn == 0) { // Player1 turn
      printf("Player 1 to move\n");
      // Wait al semaforo 1 (player 2)
      sem_oper.sem_num = sem_pl2;
      sem_oper.sem_op = -1;
      semop(semid, &sem_oper, 1);

      // Signal al semaforo 0 (player 1)
      sem_oper.sem_num = sem_pl1;
      sem_oper.sem_op = 1;
      semop(semid, &sem_oper, 1);
    }
    else { // Player 2 turn
      printf("Player 2 to move\n");
      // Wait al semaforo 0 (player 1)
      sem_oper.sem_num = sem_pl1;
      sem_oper.sem_op = -1;
      semop(semid, &sem_oper, 1);

      // Signal al semaforo 1 (player 2)
      sem_oper.sem_num = sem_pl2;
      sem_oper.sem_op = 1;
      semop(semid, &sem_oper, 1);
    }

    // Wait al semaforo 2 (engine)
    sem_oper.sem_num = sem_eng;
    sem_oper.sem_op = -1;
    semop(semid, &sem_oper, 1);

    makeMove(addr[0].position, addr[0].value);
    turn != turn;
    game_eval = evaluateGame();
    printGame();
  }
  addr[0].value = END;

  // Signal al semaforo 0 (player 2)
  sem_oper.sem_num = sem_pl1;
  sem_oper.sem_op = 1;
  semop(semid, &sem_oper, 1);

  // Signal al semaforo 1 (player 2)
  sem_oper.sem_num = sem_pl2;
  sem_oper.sem_op = 1;
  semop(semid, &sem_oper, 1);

  printf("Game result:\n");

  if(game_eval == 1) {
    printf("Player 1 won :)\n");
  }else if(game_eval == -1){
    printf("Player 2 won :)\n");
  }else {
    printf("Draw :/\n");
  }

  semctl(semid, 1, IPC_RMID, 0);
  shmdt(addr);
  shmctl(shmid, IPC_RMID, 0);
  return 0;
}
