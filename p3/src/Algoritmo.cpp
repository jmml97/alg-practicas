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

Solucion AlgoritmoGreedyAGM(Problema p) {

    Solucion S; // Solución a devolver
    int num_nodos = p.getNumNodos(); // Número de candidatos sin utilizar
    int candidatos_restantes;
    int incidencias[num_nodos]; // Vector de incidencias de cada nodo (LC)

    // Inicializar la lista de candidatos (LC)
    for (int i = 0; i < num_nodos; i++)
      LC[i] = p.getNumIncidencias(i);

    candidatos_restantes = num_nodos;
    while (candidatos_restantes > 0) { // Mientras la lista de candidatos no esté vacía...
      int max;

      // Seleccionamos el nodo con más incidencias
      max = max(incidencias, num_nodos);

      // Quitar los nodos de la LC
      if (!LC[origen])
          LC[origen] = true;
      else
          LC[destino] = true;
      --candidatos_restantes;
    }

    // Añadir la arista (origen, destino) a la solución
    S.addArista(origen, destino);

    delete[] LC;
    return S;
}
