/**
 * Algoritmo.h
 *
 * Cabeceras de las funciones empleadas para resolver el problema.
 */

#ifndef _ALGORITMO_H_
#define _ALGORITMO_H_

#include "TableroAjedrez.h"

/**
 * Decide si es factible colocar el caballo en una posición del tablero,
 * es decir, si la posición está dentro del tablero y no ha sido ocupada.
 */
bool esFactible(const TableroAjedrez& tablero, const Posicion& pos);

/**
 * Algoritmo Backtracking para resolver el problema de los movimientos del caballo
 * @param  tablero Tablero de ajedrez (cuadrado)
 * @param  pos_actual Posición del caballo en el paso actual
 * @param  paso Paso actual del recorrido del caballo; 1 <= paso <= n^2
 * @return true si se puede continuar explorando el árbol de movimientos en el
 * paso actual.
 */
bool MovimientosCaballoBT(TableroAjedrez& tablero, const Posicion& pos_actual, int paso);

#endif
