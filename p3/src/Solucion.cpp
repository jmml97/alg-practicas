#include "Solucion.h"

Solucion::Solucion() {
  coste= 0;
}

Solucion::Solucion(const Solucion & s) {
  coste = s.coste;
  delete[] nodos;
  nodos = new int[coste];
  
  for(int i = 0; i < coste; ++i)
    nodos[i] = s.nodos[i];
}


Solucion::~Solucion() {
  delete[] nodos;
}

Solucion & Solucion::operator=(const Solucion & s) {

  if (this == &s)
    return *this;

  coste = s.coste;
  delete[] nodos;
  nodos = new int[coste];
  
  for(int i = 0; i < coste; ++i)
    nodos[i] = s.nodos[i];

  return *this;
}

int Solucion::getCoste() {

  return coste;
}

void Solucion::addNodo(int nodo) {
  coste++;
  delete[] nodos;
  nodos = new int[coste];
  nodos[coste-1] = nodo;
}
