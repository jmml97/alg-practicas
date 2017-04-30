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

bool Problema::cargarDesdeFlujo(const char *nombreFichero) {

    /*
        Formato del fichero
        Línea 1: N (número de plazas, > 0
        Línea 2 hasta N+1: Nombres de las plazas
        Las demás líneas tienen el siguiente formato:
            i j p s
        Donde "i" es el código de una plaza origen, "j" es el código de otra plaza destino,
        "p" es el precio de la calle y "s" el nombre de la misma
        Ver ejemplo: Problema.dat
    */

    // Liberar memoria si la hubiese
    if (N!= 0) {

        delete [] nombresPlazas;
        for (unsigned int i= 0; i<N; i++) {
            delete [] nombresCalles[i];
            delete [] precioCalles[i];
        }
        delete [] nombresCalles;
        delete [] precioCalles;
    }

    // Inicializar a problema vacío
    N= 0;

    ifstream fichero;

    fichero.open( nombreFichero );
    if ( !fichero )
        return false;

    fichero >> N;
    if (N<=0) {
        fichero.close();
        N= 0;
        return false;
    }

    // Reserva de la memoria para el "N" nuevo
    nombresPlazas= new string[N];
    nombresCalles= new string*[N];
    precioCalles= new double *[N];

    for (unsigned int i= 0; i<N; i++) {

        nombresPlazas[i]= "";

        nombresCalles[i]= new string[N];
        precioCalles[i]= new double[N];

        for (unsigned int j= 0; j<N; j++) {

            nombresCalles[i][j]= "";
            precioCalles[i][j]= -1;
        }
    }

    // Leemos plazas
    for (unsigned int i= 0; i<N; i++)
        fichero >> nombresPlazas[i];

    while (!fichero.eof()) {

        int i, j;
        double p;
        string s;

        fichero >> i >> j >> p >> s;
        nombresCalles[i][j]= s;
        precioCalles[i][j]= p;
        nombresCalles[j][i]= s;
        precioCalles[j][i]= p;
    }

    fichero.close();

/*
    cout << "N= " << N << endl;
    for (unsigned int i= 0; i<N; i++)
        cout << "Plaza " << nombresPlazas[i] << endl;

    for (unsigned int i= 0; i<N; i++)
        for (unsigned int j= 0; j<N; j++)
            if (precioCalles[i][j] != -1) {
                cout << "i=" << i<< " j=" << j << " p=" <<precioCalles[i][j] << " ";
                cout << nombresCalles[i][j]<<endl;
            }
*/

    return true;
}


int Problema::getNumPlazas() {

    return (int)N;
}


