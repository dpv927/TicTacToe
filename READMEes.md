<div class="languages" align="center">

# Tres en Raya

:uk: <a href="https://github.com/dpv927/tic-tac-toe">English</a>
:es: <a href="#">Español</a>
</div>

## Sobre el projecto
El Tres en raya es un juego de mesa muy famoso y es muy fácil de implementar en código. Debido a esto, quería hacerlo un poco más desafiante sin cambiar los
conceptos básicos del juego. Para lograr esto, implementé el juego utilizando los semáforos del sistema y la memoria compartida de `API System 5` de Linux 
para gestionar los turnos de ambos jugadores y el control del tablero.

## Cómo usar
El juego solicita a ambos jugadores las coordenadas de su próximo movimiento. Primero, pide la fila y luego la columna. Digamos que una coordenada está 
compuesta por (fila, columna). La visualización del tablero es la siguiente:
```
+-------+-------+-------+
| (0,0) | (0,1) | (0,2) |
+-------+-------+-------+ Esas son las coordenadas del
| (1,0) | (1,1) | (1,2) | tablero de juego
+-------+-------+-------+
| (2,0) | (2,1) | (2,2) |
+-------+-------+-------+

```
Veamos un ejemplo:
```
+---+---+---+
| x |   |   |
+---+---+---+   Podemos ver que el jugador 'x' ha hecho un movimiento en
|   |   |   |   (0,0), y el jugador 'o' en (2,1).
+---+---+---+
|   | o |   |
+---+---+---+
```
La aplicación, para representar el juego, utiliza el símbolo `x` para el jugador1 y `o` para el jugador2. 

## Compila e Instala
Para compilar y gestionar todos los archivos del proyecto, se ha creado el script `Makefile`. Este script puede recibir diferentes instrucciones como
parámetros, las cuales serán verificadas y ejecutadas en el proyecto. Veamos algunos ejemplos:

```bash
make clean # Borra los archivos .o y el antiguo ejecutable del directorio actual
make # Compila el proyecto
```

## Estructura

```
tic-tac-toe/
├── CONTRIBUTORS
├── doc
│   ├── help.txt
│   └── version.txt
├── LICENSE
├── READMEes.md
├── README.md
├── src
│   ├── board.c
│   ├── board.h
│   ├── constants.h
│   ├── dependencies.txt
│   ├── main.c
│   ├── Makefile
│   ├── resources.c
│   ├── resources.h
│   ├── search.c
│   ├── search.h
│   ├── utils.c
│   └── utils.h
└── tic-tac-toe.6

3 directorios, 19 archivos
```
