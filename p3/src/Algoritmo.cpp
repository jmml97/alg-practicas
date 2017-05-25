/**
 * Implementación del algoritmo Greedy que resuelve
 * el problema del recubrimiento de un grafo no dirigido.
 *
 */

#include "Algoritmo.h"
#include <iostream>

using namespace std;

/**
 * Función de selección. Devuelve el nodo con mayor número
 * de incidencias de la lista de candidatos, cuyo tamaño es N.
 */
int FSeleccion(int* LC, int N) {
  int pos_max = 0;
  for (int i = 1; i < N; i++) {
    if (LC[i] > LC[pos_max])
      pos_max = i;
  }
  return pos_max;
}

Solucion RecubrimientoGrafoGreedy(const Problema& p) {

  Solucion sol; // Solución a devolver
  int num_nodos = p.getNumNodos();  // Número de candidatos sin utilizar
  int incidencias[num_nodos];  // Vector de incidencias de cada nodo (LC)
  int pos_max;

  // Inicializar la lista de candidatos (LC)
  for (int i = 0; i < num_nodos; ++i)
    incidencias[i] = p.getNumIncidencias(i);

  // Nodo con más incidencias
  pos_max = FSeleccion(incidencias, num_nodos);

  while (incidencias[pos_max] > 0) { // Mientras el vector de incidencias no sea {0,0,...,0}
    // Añadir el nodo con más incidencias a la solución (siempre es factible)
    sol.addNodo(pos_max);

    // Eliminar el nodo de la LC
    incidencias[pos_max] = 0;

    // Decrementar número de incidencias de nodos conectados con el seleccionado
    for (int j = 0; j < num_nodos; ++j) {
      if (p.estanConectados(pos_max,j) && incidencias[j] > 0)
	       --incidencias[j];
    }

    // Seleccionar nodo con más incidencias
    pos_max = FSeleccion(incidencias, num_nodos);
  }

  return sol;
}
