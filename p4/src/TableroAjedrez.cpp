/**
 * Tablero.cpp
 *
 * Implementación de métodos de la clase TableroAjedrez.
 *
 */

#include "TableroAjedrez.h"

using namespace std;

Posicion operator+(const Posicion &pos1, const Posicion& pos2) {
  return {pos1.i + pos2.i, pos1.j + pos2.j};
}

TableroAjedrez::TableroAjedrez(int tam) {
  if (tam > MAX)
    tam = MAX;

  tablero = new int*[tam];
  for (int i = 0; i < tam; ++i) {
    tablero[i] = new int[tam];
    for (int j = 0; j < tam; ++j)
      tablero[i][j] = 0;
  }

  this->tam = tam;
}

TableroAjedrez::TableroAjedrez(const TableroAjedrez& t) {
  tam = t.tam;
  tablero = new int*[tam];
  for (int i = 0; i < tam; ++i) {
    tablero[i] = new int[tam];
    for (int j = 0; j < tam; ++j)
      tablero[i][j] = t.tablero[i][j];
  }
}

TableroAjedrez& TableroAjedrez::operator=(const TableroAjedrez& t) {
  TableroAjedrez aux(t);

  // Swap tam
  int p = tam;
  tam = aux.tam;
  aux.tam = p;

  // Swap tablero
  int** q = tablero;
  tablero = aux.tablero;
  aux.tablero = q;

  return *this;
}

TableroAjedrez::~TableroAjedrez() {
  for (int i = 0; i < tam; ++i)
    delete[] tablero[i];

  delete[] tablero;
  tam = 0;
}
