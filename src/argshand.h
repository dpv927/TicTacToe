#ifndef ARGSHAND_H
#define ARGSHAND_H

/* @brief Comprueba si una cadena se encuentra en el array de argumentos de
 * entrada del programa como parametro, y si es asi, devuelve la el siguiente
 * parametro.
 *
 * Un ejemplo puede ser cuando le mandamos al programa ./Bandera -n 300 y queremos
 * saber que parametro o valor hay depues del parmetro '-n'.
 *
 * @param str_to_find Argumento a encontrar
 * @param int numero de argumentos
 * @param arg argumentos del programa
 *
 * @return Siguiente argumentos al buscado. Si no se encuentra, devuelve NULL, 
 * puntero a 0.
 * */
char *GetArg(char const *str_to_find, int narg, char **arg);

/* @brief Comprueba si una cadena se encuentra en el array de argumentos de
 * entrada del programa como parametro.
 *
 * @param str_to_find Argumento a encontrar
 * @param int numero de argumentos
 * @param arg argumentos del programa
 *
 * @return Si se encuentra, devuelve 1, en caso contrario 0.
 * */
int ExistArg(char const *str_to_find, int narg, char **arg);

#endif
