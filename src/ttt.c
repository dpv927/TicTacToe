#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "resources.h"

/*
 * TODO:
 * - Crear una variable que sea un puntero para el calculo
 *   del proximo movimiento de un jugador. ES una debido a que solo
 *   necesitamos saber el metodo de evaluacion para el juagdor 2, ya que
 *   el jugador 1 siempre sera humano.
 *
 * - Tras las comparaciones de los argumentos, copiar y pegar lo que
 *   se encuentra en el main.c.
 * 
 * - Cambiar la asignacion del proximo movimiento por medio del nuevo
 *   puntero obtenido por los parametros del programa.
 *
 *  - Crear uno o varios archivos .h y .c, los cuales contengan las funciones
 *    para el calculo del proximo movimiento. Preferiblemente, crear una
 *    nueva carpeta que contenga estos archivos.
 * */
int main(int argc, char *argv[]) {
  
  if(argc != 2) {
    fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0mInvalid number of arguments!\nexiting...\n");
    exit(1);
  }

  if (strcmp(argv[1], "--version") == 0){
    printdoc("../doc/version.txt"); 
  } 
  else if (strcmp(argv[1], "--help") == 0){
    printdoc("../doc/help.txt");
  }
  else if(strcmp(argv[1], "--player-mode") == 0) {
    /* Incluir el header que contenga la funcion de proximo 
     * movimiento de jugador. Asignar la funcion importada
     * al puntero de la funcion, para el jugador 2.*/
  } 
  else if(strcmp(argv[1], "--ai-mode") == 0) {
    /* Incluir el header que contenga la funcion de proximo 
     * movimiento de la IA. Asignar la funcion importada
     * al puntero de la funcion, para el jugador 2.*/
  } 
  else {
    fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0mUnrecognized option: %s\nexiting...\n", argv[1]);
  }
  return 0;
}
