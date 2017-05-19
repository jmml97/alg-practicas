#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <string>

using namespace std;

/**
 * Un Problema es una matriz de adyacencia simétrica, junto
 * con su dimensión.
 */
class Problema
{
  public:
    
    Problema();
    Problema(const Problema& p);
    Problema & operator=(const Problema& p);
    ~Problema();

    /**
     * Carga un problema desde el fichero dado por argumento.
     * @return true si se ha cargado, false si hubo algun error
     */
    bool cargarDesdeFlujo(const char *nombre_fichero);

    int getNumNodos();

    /**
     * Devuelve el número de incidencias del i-ésimo nodo
     */
    int getNumIncidencias(int i);

    /**
     * Devuelve true si hay un camino entre el nodo i y el nodo j,
     * o false si no lo hay.
     */
    bool estanConectados(int i, int j);

  private:

    int tam;  // Tamaño de la matriz
    bool **matriz_adyacencia;

};

#endif // PROBLEMA_H
