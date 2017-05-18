#include "Problema.h"
#include <fstream>
#include <iostream>

using namespace std;


Problema::Problema() {

    N= 0;
}


Problema::Problema(const Problema & p) {

    N= 0;
    *this= p;
}


Problema & Problema::operator=(const Problema &p) {

    if (&p == this) // Para evitar cosas como mivariables= mivariables
        return *this;


    if (N > 0) { // Liberar la memoria previa

        delete [] nombresPlazas;
        for (unsigned int i= 0; i<N; i++) {
            delete [] nombresCalles[i];
            delete [] precioCalles[i];
        }
        delete [] nombresCalles;
        delete [] precioCalles;
    }

    N= p.N; // Reserva de memoria nueva si es necesario y copia
    if (N>0) {

        nombresPlazas= new string[N];
        nombresCalles= new string*[N];
        precioCalles= new double *[N];

        for (unsigned int i= 0; i<N; i++) {

            nombresPlazas[i]= p.nombresPlazas[i];

            nombresCalles[i]= new string[N];
            precioCalles[i]= new double[N];

            for (unsigned int j= 0; j<N; j++) {

                nombresCalles[i][j]= p.nombresCalles[i][j];
                precioCalles[i][j]= p.precioCalles[i][j];
            }
        }

    }


    return *this;
}


Problema::~Problema() {

    if (N!= 0) {

        delete [] nombresPlazas;
        for (unsigned int i= 0; i<N; i++) {
            delete [] nombresCalles[i];
            delete [] precioCalles[i];
        }
        delete [] nombresCalles;
        delete [] precioCalles;
    }
}

string Problema::getNombrePlaza(int i) {

    if (i<0 || i>=(int)N)
        return "";

    return nombresPlazas[i];
}

string Problema::getNombreCalle(int i, int j) {

    if (i<0 || i>=(int)N || j<0 || j>=(int)N)
        return "";

    return nombresCalles[i][j];
}


double Problema::getPrecioCalle(int i, int j) {

    if (i<0 || i>=(int)N || j<0 || j>=(int)N)
        return -1;

    return precioCalles[i][j];
}

bool Problema::cargarDesdeFlujo(const char *nombre_fichero) {

    /*
      Formato del fichero
      Línea 1: N (tamaño de la matriz cuadrada)
      Línea 2 hasta N+1: Matriz de adyacencia
      En la matriz de adyacencia, la posición (i, j)
      indica si el nodo i está conectado con el nodo j
    */

    // Liberar memoria si la hubiese
    if (tam != 0) {

        for (unsigned int i= 0; i<N; i++) {
            delete [] matriz_adyacencia[i];
        }

        delete [] matriz_adyacencia;
    }

    // Inicializar a problema vacío
    N = 0;

    // Intenemos abrir el archivo
    ifstream fichero;
    fichero.exceptions (ifstream::failbit | ifstream::badbit);

    try {
      fichero.open(nombreFichero);
    }

    catch (ifstream::failure &e) {
      cout << "Error en la lectura del archivo: " << nombreFichero << endl
      cerr << "Excepción: " << e << endl;
    }

    // Leemos el tamaño de la matriz (primera línea del fichero)
    fichero >> N;

    if (N <= 0) {
        fichero.close();
        N = 0;
        return false;
    }

    // Reserva de la memoria para el "N" nuevo
    matriz_adyacencia = new bool*[N];

    for (unsigned int i = 0; i < N; i++) {
        matriz_adyacencia[i] = new bool[N];
    }

    // Leemos la matriz
    while (!fichero.eof()) {

      for (size_t i = 0; i < N; i++) {
        fichero >> matriz_adyacencia[i];
      }

    }

    fichero.close();

    return true;
}


int Problema::getNumNodos() {
    return N;
}

int Problema::getNumIncidencias(int i) {
    incidencias = 0;
    for (int j = 0; j < N; j++)
      incidencias += L[i][j];

    return incidencias;
}
