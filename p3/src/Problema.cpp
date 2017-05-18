#include "Problema.h"
#include <fstream>
#include <iostream>

using namespace std;

Problema::Problema() {
    tam = 0;
}

Problema::Problema(const Problema & p) {
    tam = 0;
    *this= p;
}

Problema & Problema::operator=(const Problema &p) {

    if (&p == this) // Para evitar cosas como mivariables= mivariables
        return *this;


    if (tam > 0) { // Liberar la memoria previa
        for (unsigned int i= 0; i < tam; i++) {
            delete [] matriz_adyacencia[i];
        }
        delete [] matriz_adyacencia;
    }

    tam = p.tam; // Reserva de memoria nueva si es necesario y copia
    if (tam > 0) {
      matriz_adyacencia= new bool *[tam];

      for (unsigned int i= 0; i < tam; i++) {
        matriz_adyacencia[i] = new bool[tam];

        for (unsigned int j= 0; j < tam; j++) {
          matriz_adyacencia[i][j]= p.matriz_adyacencia[i][j];
        }
      }
    }

    return *this;
}

Problema::~Problema() {
    if (tam != 0) {
        for (unsigned int i= 0; i < tam; i++) {
            delete [] matriz_adyacencia[i];
        }
        delete [] matriz_adyacencia;
    }
}

bool Problema::cargarDesdeFlujo(const char *nombre_fichero) {

    /*
      Formato del fichero
      Línea 1: tam (tamaño de la matriz cuadrada)
      Línea 2 hasta tam+1: Matriz de adyacencia
      En la matriz de adyacencia, la posición (i, j)
      indica si el nodo i está conectado con el nodo j
    */

    // Liberar memoria si la hubiese
    if (tam != 0) {

        for (unsigned int i = 0; i < tam; i++) {
            delete [] matriz_adyacencia[i];
        }

        delete [] matriz_adyacencia;
    }

    // Inicializar a problema vacío
    tam = 0;

    // Intenemos abrir el archivo
    ifstream fichero;
    //fichero.exceptions ( ifstream::failbit | ifstream::badbit );

    //fichero.open(nombre_fichero);

    try {
      fichero.open(nombre_fichero);
    }

    catch (const ifstream::failure &e) {
      cerr << "Error en la lectura del archivo: " << nombre_fichero << endl;
    }

    // Leemos el tamaño de la matriz (primera línea del fichero)
    fichero >> tam;

    if (tam <= 0) {
        fichero.close();
        tam = 0;
        return false;
    }

    // Reserva de la memoria para el "tam" nuevo
    matriz_adyacencia = new bool*[tam];

    for (unsigned int i = 0; i < tam; i++) {
        matriz_adyacencia[i] = new bool[tam];
    }

    // Leemos la matriz
    while (!fichero.eof()) {

      for (size_t i = 0; i < tam; i++) {
        for (size_t j = 0; j < tam; j++) {
          fichero >> matriz_adyacencia[i][j];
        }
      }

    }

    fichero.close();

    return true;
}

int Problema::getNumNodos() {
    return tam;
}

int Problema::getNumIncidencias(int i) {
    int incidencias = 0;
    for (int j = 0; j < tam; j++)
      incidencias += matriz_adyacencia[i][j];

    return incidencias;
}

bool Problema::estanConectados(int i, int j) {
  return matriz_adyacencia[i][j];
}
