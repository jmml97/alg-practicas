#include "Solucion.h"

Solucion::Solucion() {
  coste = 0;
  nodos = 0;
}

Solucion::Solucion(const Solucion& s) {
  coste = s.coste;
  delete[] nodos;
  nodos = new int[coste];

  for (int i = 0; i < coste; ++i)
    nodos[i] = s.nodos[i];
}

Solucion::~Solucion() {
  if (coste != 0)
    delete[] nodos;
  coste = 0;
}

Solucion & Solucion::operator=(const Solucion& s) {
  if (this == &s)
    return *this;

  if (coste != 0)
    delete[] nodos;

  coste = s.coste;
  nodos = new int[coste];

  for(int i = 0; i < coste; ++i)
    nodos[i] = s.nodos[i];

  return *this;
}

int Solucion::getNodo(int i) {
  return nodos[i];
}

int Solucion::getCoste() {
  return coste;
}

void Solucion::addNodo(int nodo) {
  int* aux = new int[coste+1];
  for (int i = 0; i < coste; i++)
    aux[i] = nodos[i];

  if(coste != 0)
    delete[] nodos;

  aux[coste++] = nodo;

  nodos = aux;
}
