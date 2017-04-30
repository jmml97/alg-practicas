#include "Solucion.h"

Solucion::Solucion() {

    Num= 0;
    coste= 0;
}

Solucion::Solucion(const Solucion & s) {

    Num= 0;
    coste= 0;
    *this= s;
}


Solucion::~Solucion() {

    if (Num > 0) {

        delete [] Aristas[0];
        delete [] Aristas[1];
        delete [] Aristas;
    }
}


Solucion & Solucion::operator=(const Solucion & s) {

    if (this == &s)
        return *this;

    if (Num > 0) {

        delete [] Aristas[0];
        delete [] Aristas[1];
        delete [] Aristas;
    }

    Num= s.Num;
    coste= s.coste;
    if (Num > 0) {

        Aristas= new int *[2];
        Aristas[0]= new int[Num];
        Aristas[1]= new int[Num];

        for (int i= 0; i<Num; i++) {
            Aristas[0][i]= s.Aristas[0][i];
            Aristas[1][i]= s.Aristas[1][i];
        }
    }

    return *this;
}



void Solucion::getArista(int a, int &origen, int &destino) {

    if (a < 0 || a >= Num) {

        origen= destino= -1;
    } else {

        origen= Aristas[0][a];
        destino= Aristas[1][a];
    }
}



double Solucion::getCoste() {

    return coste;
}



void Solucion::Evaluar(Problema p) {

    coste= 0;

    for (int i= 0; i<Num; i++) {

        int costeArista;

        costeArista= p.getPrecioCalle( Aristas[0][i], Aristas[1][i] );

        if (costeArista == -1) {

            coste= -1;
            return;
        }
        coste+= costeArista;
    }
}


void Solucion::addArista(int origen, int destino) {

    bool esta= false;
    int **aux;

    for (int i= 0; i<Num && !esta; i++) {

        if ((Aristas[0][i] == origen && Aristas[1][i] == destino) ||
            (Aristas[0][i] == destino && Aristas[1][i] == origen))
                esta= true;
    }

    if (esta) return;

    aux= new int *[2];
    aux[0]= new int[Num+1];
    aux[1]= new int[Num+1];

    for (int i= 0; i<Num; i++) {
        aux[0][i]= Aristas[0][i];
        aux[1][i]= Aristas[1][i];
    }
    aux[0][Num]= origen;
    aux[1][Num]= destino;

    if (Num > 0) {

        delete [] Aristas[0];
        delete [] Aristas[1];
        delete [] Aristas;
    }
    Num++;

    Aristas= aux;

}



int Solucion::getNumAristas() {

    return Num;
}

