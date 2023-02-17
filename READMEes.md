<div class="languages" align="center">

# Tic-Tac-Toe

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
Para compilar y gestionar todos los archivos del proyecto, se ha creado el script `build.sh`. Este script puede recibir diferentes instrucciones como
parámetros, las cuales serán verificadas y ejecutadas en el proyecto. Veamos algunos ejemplos:
```bash
./build cleanf # Elimina los archivos antiguos como ejecutables y otros archivos objeto.
./build generate # Compila y genera un archivo ejecutable.
./build generate-verbose # Compila y genera un archivo ejecutable en modo detallado.
./build install # Si existe un ejecutable, lo copia a la ruta de programas.
./build cleanf generate install # Realiza en el mismo orden que se especifican todos los comandos ya descritos.
./build # Limpia y genera un ejecutable. Es lo mismo que './build cleanf generate' pero más rápido.
```
Otra característica de este script es que puedes indicarle cuantos comandos como necesites, y en el orden que desees. El script eliminará las ordenes
repetidas y las ejecutará en el orden en el que se han indicado como parámetro. Por ejemplo:
```bash
./build cleanf generate # Es lo mismo que ./build cleanf generate generate o ./build cleanf generate cleanf ...
```

Ahora que conoces los detalles, puedes compilar y gestionar el proyecto como prefieras. Por ejemplo, para realizar una compilación rápida:
```bash
./build.sh
```

## Desinstalar
Para desinstalar el programa, simplemente utiliza el script `build.sh`:
```bash
./build uninstall
```
