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
  if(coste != 0)
    delete[] nodos;
}

Solucion & Solucion::operator=(const Solucion & s) {

  if (this == &s)
    return *this;

  if(coste != 0)
    delete[] nodos;
  coste = s.coste;

  nodos = new int[coste];

  for(int i = 0; i < coste; ++i)
    nodos[i] = s.nodos[i];

  return *this;
}

int Solucion::getNodo(int i) {
  if (i < coste)
    return nodos[i];
}

int Solucion::getCoste() {

  return coste;
}

void Solucion::addNodo(int nodo) {
  if(coste != 0)
    delete[] nodos;
  coste++;
  nodos = new int[coste];
  nodos[coste-1] = nodo;
}
