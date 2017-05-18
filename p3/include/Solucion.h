#ifndef SOLUCION_H
#define SOLUCION_H

#include "Problema.h"

/**
 * Una Solucion es una colección de nodos que forman
 * el recubrimiento del grafo, junto con el coste de dicho
 * recubrimiento (número de nodos)
 *
 */
class Solucion
{
 public:
  Solucion(); // Construye una solución vacía, con coste 0 y sin nodos
  Solucion(const Solucion & s); // Constructor de copia

  ~Solucion(); // Destructor

  Solucion & operator=(const Solucion & s); // Operador de asignación

  int getNodo(int i); // Devuelve el nodo i-ésimo
  int getCoste(); // Devuelve el coste de la solución
  
  /*
    Modifica la solución actual añadiendo un nodo
  */
  void addNodo(int nodo);
  
 private:

  /*
    La solución es un vector de nodos y su coste (número de nodos). Los nodos se representarán mediante un número entre 1 y el número total de nodos. El tamaño del recubrimiento será menor o igual que el número total de nodos.

    El número total de nodos es p.getNumNodos(), donde "p" es un objeto de la clase "Problema". 
  */
  int coste; // Coste de la solución, número de nodos
  int *nodos;
};

#endif // SOLUCION_H
