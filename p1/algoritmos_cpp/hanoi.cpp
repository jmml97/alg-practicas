/**
   @file Resolución del problema de las Torres de Hanoi
*/


#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>

#define PRINT_DATA 0

/**
   @brief Resuelve el problema de las Torres de Hanoi
   @param M: número de discos. M > 1.
   @param i: número de columna en que est�n los discos.
             i es un valor de {1, 2, 3}. i != j.
   @param j: número de columna a que se llevan los discos.
             j es un valor de {1, 2, 3}. j != i.

   Esta función imprime en la salida estándar la secuencia de
   movimientos necesarios para desplazar los M discos de la
   columna i a la j, observando la restricción de que ningún
   disco se puede situar sobre otro de tamaño menor. Utiliza
   una �nica columna auxiliar.
*/
void hanoi (int M, int i, int j);


void hanoi (int M, int i, int j)
{
  if (M > 0)
    {
      hanoi(M-1, i, 6-i-j);
      #if PRINT_DATA
        cout << i << " -> " << j << endl;
      #endif
      hanoi (M-1, 6-i-j, j);
  }
}

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    cout << "\nUso: ./hanoi nº_discos";
    return 1;
  }
  clock_t tantes, tdespues;
  int M = atoi(argv[1]);

  tantes = clock();
  hanoi(M, 1, 2);
  tdespues = clock();

  cout << M << " " << (double)(tdespues - tantes) / CLOCKS_PER_SEC << endl;

  return 0;
}
