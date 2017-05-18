#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <string>

using namespace std;

class Problema
{
public:
  Problema();
  Problema(const Problema & p);
  Problema & operator=(const Problema &p);
  ~Problema();

  bool cargarDesdeFlujo(const char *nombre_fichero); // Carga un problema
  // desde el fichero dado por argumento.
  // Devuelve true si ok, y false
  // si error al cargarlo

  int getNumNodos(); // Devuelve el número de plazas del problema
  int getNumIncidencias(int i); // Devuelve el número de incidencias del nodo i-ésimo
  bool estanConectados(int i, int j);

private:

  int tam;  // Tamaño de la matriz
  bool **matriz_adyacencia;

};

#endif // PROBLEMA_H
