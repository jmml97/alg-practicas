#include "Algoritmos.h"
#include <iostream>

using namespace std;

Solucion AlgoritmoGreedyAGM(Problema p) {

    Solucion S; // Solución a devolver
    bool *LC; // Lista de candidatos (false si está en LC, true si está en LCU)
    int NumLC; // Número de candidatos sin utilizar
    int origen, destino; // Las plazas origen y destino a seleccionar en la función de selelección
    double costeCalle; // Coste de la calle (origen, destino)

    // Inicializar la lista de candidatos
    LC= new bool[ p.getNumPlazas() ];
    for (int i= 0; i<p.getNumPlazas(); i++)
        LC[i]= false;

    // Selecciono el primer elemento como el primer nodo (plaza)
    LC[0]= true;
    NumLC= p.getNumPlazas()-1;

    while (NumLC > 0) { // Mientras la lista de candidatos no esté vacía...

        // Seleccionar la plaza que una con una calle de coste mínimo con otra
        //  plaza de la LCU
        costeCalle= -1; // CosteCalle= infinito

        for (int i= 0; i<p.getNumPlazas(); i++) {

            for (int j= i+1; j<p.getNumPlazas(); j++) {

                if ((LC[i] != LC[j]) &&
                    (costeCalle==-1 ||
                     (p.getPrecioCalle(i, j) > 0 &&
                      p.getPrecioCalle(i, j) < costeCalle))) {

                    origen= i;
                    destino= j;
                    costeCalle= p.getPrecioCalle(i, j);

                }
            }
        }

        // Quitar los nodos de la LC
        if (!LC[origen])
            LC[origen]= true;
        else
            LC[destino]= true;
        NumLC--;

        // Añadir la arista (origen, destino) a la solución
        S.addArista(origen, destino);
    }

    delete [] LC;
    return S;
}
