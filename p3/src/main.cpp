#include <iostream>
#include "Problema.h"
#include "Solucion.h"
#include "Algoritmo.h"

using namespace std;

int main()
{
    Problema prob;
    //Solucion sol;

    if (!prob.cargarDesdeFlujo("Problema.dat"))
      cout << "El fichero no se puede abrir" << endl;

    cout << "num nodos:" << prob.getNumNodos() << endl;
    cout << "0,0:" << prob.estanConectados(0,0)  << endl;
    cout << "0,1:" << prob.estanConectados(0,1)  << endl;
    cout << "0,2:" << prob.estanConectados(0,2)  << endl;

    // Resolvemos con algoritmo greedy
    // sol= AlgoritmoGreedyAGM(prob);

    // La evaluamos
    // sol.Evaluar(prob);


    // Mostramos la solución final
    // for (int i= 0; i<sol.getNumAristas(); i++) {
    //
    //     int origen, destino;
    //
    //     sol.getArista(i, origen, destino);
    //     cout << "Arista: " << prob.getNombreCalle(origen, destino);
    //     cout << " con coste= " << prob.getPrecioCalle(origen, destino) <<endl;
    // }
    //
    // cout << endl << "Total calles: " << sol.getNumAristas();
    // cout << endl << "Coste total: " << sol.getCoste() << endl;

    return 0;
}
