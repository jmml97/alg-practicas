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

  string getNombrePlaza(int i); // Devuelve el nombre de la i-esima plaza
  string getNombreCalle(int i, int j); // Devuelve el nombre de la calle que
  // une las plazas en las posiciones i y j
  // o el valor "" si no existe
  double getPrecioCalle(int i, int j); // Devuelve el precio de la calle que
  // une las plazas en las posiciones i y j
  // o el valor -1 si no existe la calle

  bool cargarDesdeFlujo(const char *nombre_fichero); // Carga un problema
  // desde el fichero dado por argumento.
  // Devuelve true si ok, y false
  // si error al cargarlo

  int getNumPlazas(); // Devuelve el número de plazas del problema

  int getNumIncidencias(int i); // Devuelve el número de incidencias del nodo i-ésimo

  bool estanConectados(int i, int j);

protected:

  unsigned int N; // Número de nodos

  string **nombresCalles; // Nombres de las calles
  // nombresCalles[i][j] es el nombre de la calle
  // que une la plaza nombresPlazas[i] con la plaza
  // nombresPlazas[j], o el valor "" si no existe

  int tam;  // Tamaño de la matriz
  bool **matriz_adyacencia;


private:
};

#endif // PROBLEMA_H
