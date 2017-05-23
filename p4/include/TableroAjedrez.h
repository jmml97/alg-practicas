/**
 * Tablero.h
 *
 * Representa un tablero de ajedrez de tamaño arbitrario hasta un N fijo.
 *
 */

#ifndef _TABLERO_AJEDREZ_H
#define _TABLERO_AJEDREZ_H

const int MAX = 10;

struct Posicion {
  int i;
  int j;
};

Posicion operator+(const Posicion& pos1, const Posicion& pos2);

class TableroAjedrez {
  private:
    int tam;
    int** tablero;

  public:
    TableroAjedrez(int tam);
    TableroAjedrez(const TableroAjedrez& t);
    TableroAjedrez& operator=(const TableroAjedrez& t);
    ~TableroAjedrez();

    /**
     * Devuelve el contenido de la casilla (i,j)
     * @param  i Fila de la casilla
     * @return j Columna de la casilla
     * @pre 0 <= i < tam, 0 <= j < tam
     */
    int get(int i, int j) const {
      return tablero[i][j];
    }

    /**
     * Actualiza el contenido de la casilla (i,j) con el valor v
     * @param  i Fila de la casilla
     * @param  j Columna de la casilla
     * @param v Nuevo valor de la casilla
     * @pre 0 <= i < tam, 0 <= j < tam
     */
    void set(int i, int j, int v) {
      tablero[i][j] = v;
    }

    /**
     * Devuelve el número de elementos de la matriz
     */
    int getTam() const {
      return tam;
    }
    /**
     * Devuelve el contenido de la casilla correspondiente
     * a la Posicion pos
     * @pre 0 <= pos.i < tam, 0 <= pos.j < tam
     */
    int& operator[](const Posicion& pos) {
      return tablero[pos.i][pos.j];
    }

    const int& operator[](const Posicion& pos) const {
      return tablero[pos.i][pos.j];
    }
};

#endif
