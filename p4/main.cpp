/**
 * main.cpp
 *
 * Programa principal. Acepta los siguientes parámetros:
 *
 *    - Tamaño del tablero
 *    - Posición inicial del caballo (opcional). El formato es: `i j`, donde i y j son enteros
 *      que representan la fila y la columna en el tablero, respectivamente.
 *
 * Si no se pasa la posición inicial como parámetro, se comienza en una casilla aleatoria.
 * s
 */

#include <iostream>
#include "TableroAjedrez.h"
#include "Algoritmo.h"

using namespace std;

int main(int argc, char* argv[]) {

  if (argc <= 1) {
    cerr << "Error. Sintaxis: Tam [i] [j]" << endl;
    return 1;
  }

  srand(time(0));

  int N = stoi(argv[1]);
  TableroAjedrez tablero(N);
  Posicion pos_inicial;

  if (argc >= 4) {
    pos_inicial.i = stoi(argv[2]);
    pos_inicial.j = stoi(argv[3]);
  }
  else {
    pos_inicial.i = rand() % N;
    pos_inicial.j = rand() % N;
  }

  // Encontrar recorrido del caballo
  MovimientosCaballoBT(tablero, pos_inicial, 1);

  // Mostrar el tablero con la solución
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << tablero.get(i,j) << "  ";
    }
  cout << endl;
}

  return 0;
}
