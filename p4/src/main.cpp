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

  srand(time(0));

  if (argc <= 1) {
    cerr << "Error. Sintaxis: Tam [i] [j]" << endl;
    return 1;
  }

  int N = stoi(argv[1]);
  TableroAjedrez tablero(N);
  Posicion pos_inicial;
  bool tiene_solucion = false;
  bool sol_particular;

  if (argc >= 4) {
    pos_inicial.i = stoi(argv[2]);
    pos_inicial.j = stoi(argv[3]);
    sol_particular = true;
  }

  /*
      Encontrar recorrido del caballo.
      Sabemos que no hay solución si n < 5 (excepto la solución trivial para n = 1)
   */

  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }

  if (N >= 5) {
    if (sol_particular) {
      tiene_solucion = MovimientosCaballoBT(tablero, pos_inicial, 1);
    }
    else {
      while (!tiene_solucion) {
        pos_inicial.i = rand() % N;
        pos_inicial.j = rand() % N;
        tiene_solucion = MovimientosCaballoBT(tablero, pos_inicial, 1);
      }
    }

    if (tiene_solucion) {
      // Mostrar el tablero con la solución
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          cout << tablero.get(i,j) << "  ";
        }
      cout << endl;
      }
    }

    else {
      cout << "No hay solución en un tablero de " << N << "x" << N << " para la "
           << "casilla inicial (" << pos_inicial.i << "," << pos_inicial.j << ").\n";
    }
  }

  else {
    cout << "No hay solución en un tablero de " << N << "x" << N << ".\n";
  }

  return 0;
}
