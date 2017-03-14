/**
   @file Ordenación por burbuja
*/

#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

#define UNA_VEZ // Comentar para iterar muchas veces


/* ************************************************************ */
/*  Método de ordenación por burbuja  */

/**
   @brief Ordena un vector por el mútodo de la burbuja.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: número de elementos. num_elem > 0.

   Cambia el orden de los elementos de T de forma que los dispone
   en sentido creciente de menor a mayor.
   Aplica el algoritmo de la burbuja.
*/
inline static
void burbuja(int T[], int num_elem);

/**
   @brief Ordena parte de un vector por el método de la burbuja.

   @param T: vector de elementos. Tiene un número de elementos
                   mayor o igual a final.Es MODIFICADO.

   @param inicial: Posición que marca el incio de la parte del
                   vector a ordenar.
   @param final: Posición detrás de la última de la parte del
                   vector a ordenar.
		   inicial < final.

   Cambia el orden de los elementos de T entre las posiciones
   inicial y final - 1de forma que los dispone en sentido creciente
   de menor a mayor.
   Aplica el algoritmo de la burbuja.
*/
static void burbuja_lims(int T[], int inicial, int final);


/**
   Implementación de las funciones
**/

inline void burbuja(int T[], int num_elem)
{
  burbuja_lims(T, 0, num_elem);
};


static void burbuja_lims(int T[], int inicial, int final)
{
  int i, j;
  int aux;
  for (i = inicial; i < final - 1; i++)
    for (j = final - 1; j > i; j--)
      if (T[j] < T[j-1])
	{
	  aux = T[j];
	  T[j] = T[j-1];
	  T[j-1] = aux;
	}
}


int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    cout << "\nUso: ./burbuja nº_elementos_vector";
    return 1;
  }

  clock_t tantes, tdespues;
  const int NUM_VECES = 1000;
  double tiempo_transcurrido;
  int n = atoi(argv[1]);
  int * T = new int[n];

  bool debug = false;

  assert(T);

  srandom(time(0));

  for (int i = 0; i < n; i++)
      T[i] = random();

  #ifndef UNA_VEZ

    tantes = clock();
    for (int i = 0; i < NUM_VECES; ++i)
      burbuja(T, n);
    tdespues = clock();
    tiempo_transcurrido = ((double)(tdespues - tantes)/(CLOCKS_PER_SEC * (double)NUM_VECES));
    cout << n << " " << tiempo_transcurrido << endl;

  #else
    tantes = clock();
    burbuja(T, n);
    tdespues = clock();
    cout << n << " " << (double)(tdespues - tantes) / CLOCKS_PER_SEC << endl;

  #endif

  delete [] T;

  return 0;
};
