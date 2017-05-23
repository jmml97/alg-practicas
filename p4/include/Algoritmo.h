/**
 * Algoritmo.h
 *
 */

#ifndef _ALGORITMO_H_
#define _ALGORITMO_H_

#include "TableroAjedrez.h"

bool esFactible(const TableroAjedrez& tablero, const Posicion& pos);

bool MovimientosCaballoBT(TableroAjedrez& tablero, const Posicion& pos_actual, int paso);

#endif
