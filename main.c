#include <stdio.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include "board.h"
#define KEY 100
#define sem_pl1 0
#define sem_pl2 1

int main() {
  
  /* Objetivos de la aplicacion:--------------------------------------------------------- 
   *
   * La cosa seria empezar un tablero nuevo, aunque exista ya uno. Este seria el 
   * proceso central, que lee los buffers tanto del jugador1 como del jugador2. 
   *
   * Los bufers contendran la informacion de los movimientos que cada jugador
   * quiere realizar. 
   *
   * Tambien se dedicaria a sincronizar ambos jugadores, de forma que la partida
   * tenga un orden logico, y que ambos jugadores relizen sus movimientos sin
   * interrumpir al otro jugador.
   *
   * Tras ello, procesaria las entradas de los movimientos y las aplicaria al
   * tablero. Finalmente controlaria si la partida ha finalizado y en caso afirmativo
   * decir que jugador ha ganado o si ha habido empate.
   *
   * Implementacion:----------------------------------------------------------------------
   *
   * Se deberia hacer un segmento de memoria compartida para los procesos del jugador1, 
   * jugador2 y el motor del juego. El segmento de memoria compartida deberia ser un puntero
   * a chars, de forma que se pueda obtener un string que represente la coordenada jugada
   * por cada jugador. Esta tendra una capacidad de 2 caracteres.
   *
   * Se deberá crear dos semáforos, uno para cada proceso de los jugadores, de manera que
   * cuando un jugador escriba en el buffer (haga un movimiento), este se bloquee y el 
   * otro se active y asi sucesivamente durante toda la partida. 
   *  
   * El tablero tendra la siguiente notacion:
   *   
   * +---+---+---+
   * | 0 | 1 | 2 |
   * +---+---+---+
   * | 3 | 4 | 5 |
   * +---+---+---+
   * | 6 | 7 | 8 |
   * +---+---+---+
   * 
   * El tablero se diseñara como un array de enteros de 9 posiciones, en el cual las marcas
   * de los jugadores serán: 1 para el jugador1 y -1 para el jugador2. */
  
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

  semid = semget(KEY, 2, IPC_CREAT | 0700);
  if(semid == -1) {
    printf("Error accessing or creating the semaphores.\n");
    exit(-1);
  }

  arg.array = (unsigned short *)malloc(sizeof(short) * 2);
  arg.array[sem_pl1] = 1; // Jugador 1 inicialmente desbloqueado
  arg.array[sem_pl2] = 0; // Jugador 2 inicialmente bloqueado
  semctl(semid, 2, SETALL, arg);

  shmid = shmget(KEY, sizeof(int) * 2, IPC_CREAT | 0700);
  if(semid == -1) {
    printf("Error accessing or creating the shared memory.\n");
    exit(-1);
  } 

  addr = shmat(shmid, 0, 0);
  game_eval = -2;
  turn = 0;
 
  while(game_eval == -2 /*Game is on*/) {
    if(turn == 0) { // Player1 turn
      // Wait al semaforo 1 (player 2)
      // Signal al semaforo 0 (player 1)
    }
    else { // Player 1 turn
      // Wait al semaforo 0 (player 1)
      // Signal al semaforo 1 (player 2) 
    }
    turn != turn;
    game_eval = evaluateGame();
  }

  semctl(semid, 1, IPC_RMID, 0);
  shmdt(addr);
  shmctl(shmid, IPC_RMID, 0);
  return 0;
}
