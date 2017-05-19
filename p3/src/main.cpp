#include <iostream>
#include "Problema.h"
#include "Solucion.h"
#include "Algoritmo.h"

using namespace std;

int main(int argc, char* argv[]) {
  Problema prob;
  Solucion sol;

  if (argc < 2) {
    cout << "Número de argumentos inválido" << endl;
    return 0;
  }

  if (!prob.cargarDesdeFlujo(argv[1]))
    cout << "El fichero no se puede abrir" << endl;

  // Resolvemos con algoritmo greedy
  sol = RecubrimientoGrafoGreedy(prob);

  // Mostramos la solución final
  cout << "Nodos:\n" << endl;
  for (int i = 0; i < sol.getCoste(); i++)
    cout << sol.getNodo(i) << " ";
  cout << "\nNúmero de nodos utilizados: " << sol.getCoste();
  cout << endl;

  return 0;
}
