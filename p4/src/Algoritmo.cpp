/**
 * Algoritmo.cpp
 *
 * Implementación del algoritmo Backtracking que resuelve el problema
 * de los movimientos del caballo.
 *
 */

#include "Algoritmo.h"

using namespace std;

namespace {
  // Posibles movimientos del caballo relativos a la casilla donde está
  Posicion movimientos[8] = { {2,1}, {2,-1}, {-2,1}, {-2,-1},
                              {1,2}, {1,-2}, {-1,2}, {-1,-2} };
}

bool esFactible(const TableroAjedrez& tablero, const Posicion& pos) {
  bool en_tablero = pos.i < tablero.getTam() && pos.i >= 0
                  && pos.j < tablero.getTam() && pos.j >= 0;

  return en_tablero && tablero[pos] == 0;
}

bool MovimientosCaballoBT(TableroAjedrez& tablero, const Posicion& pos_actual, int paso) {
  tablero[pos_actual] = paso;

  // Si estamos en el último paso
  if (paso == tablero.getTam()*tablero.getTam())
    return true;

  for (int k = 0; k < 8; ++k) {
    bool ok;
    Posicion pos_nueva = pos_actual + movimientos[k];

    if (esFactible(tablero, pos_nueva)) {
      ok = MovimientosCaballoBT(tablero, pos_nueva, paso + 1);

      if (!ok)
        tablero[pos_nueva] = 0;
      else
        return true;
    }
  }

  // Si sale del bucle, es que no puede colocar en ninguna casilla.
  return false;
}
