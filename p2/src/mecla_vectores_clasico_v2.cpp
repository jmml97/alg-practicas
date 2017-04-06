
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
//#include <algorithm>
//#include <vector>

// Mezcla K vectores de N tamaño pasados por T y que se guardan en res
// Cuidado, hay que crear res de tamaño N = nk
void MezclarK(int** T, int* res, int n, int k)
{
  // Tamaño total del vector
  int N = n * k;
  
  // Vector donde vamos a guardar el indice del valor que falta por meter de cada vector
  int* v_indices = new int[k];

  // Inicializamos al último indice de cada vector (los máximos)
  for (int i = 0; i < k; ++i)
    v_indices[i] = n - 1;

  // El bucle dura hasta N = nk colocados; empezamos en N y acabamos en -1
  int indice_colocar = N - 1;
  while (indice_colocar >= 0)
  {
    // Este indice indica que vector es el que contiene el valor max.
    int indice_max = 0;
    // Recorremos buscando el indice que contenga el valor mayor
    for (int i = 0; i < k; ++i)
      if (T[indice_max][v_indices[indice_max]] < T[i][v_indices[i]])
        indice_max = i;
    // Guardamos en res con el valor correspondiente
    res[indice_colocar] = T[indice_max][v_indices[indice_max]];
    // Decrementamos el indice corresponiente al vector que acabamos de usar
    --v_indices[indice_max];
    // Hemos colocado uno
    --indice_colocar;
  }

  delete [] v_indices;
}

//generador de ejemplor para el problema de mezcla de k vectores ordenados. Para obtener k vectores ordenados de forma creciente cada uno con n elementos, genera un vector de tamaño $k*n$ con todos los enteros entre 0 y kn-1 ordenados. Se lanzan entonces k iteraciones de un algoritmo de muestreo aleatorio de tamaño n para obtener los k vectores. Están ordeados porque el algoritmo de muestreo mantiene el orden

double uniforme() //Genera un número uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C.
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}

int main(int argc, char * argv[])
{
  if (argc != 3) {
    cerr << "Formato " << argv[0] << " <num_elem>" << " <num_vect>" << endl;
    return -1;
  }

  int n = atoi(argv[1]);
  int k = atoi(argv[2]);

  int **T;
  T =  new int * [k];
    assert(T);

  for (int i = 0; i < k; i++)
    T[i]= new int [n];

  int N = k * n;
  int * aux = new int[N];
  assert(aux);

  srand(time(0));
  //genero todos los enteros entre 0 y $k*n-1$
  for (int j = 0; j < N; j++)
    aux[j]=j;

  //para cada uno de los k vectores se lanza el algoritmo S (sampling) de Knuth
  for (int i = 0; i < k; i++) {
    int t = 0;
    int m = 0;
    while (m < n) {
      double u = uniforme();
      if ((N - t) * u >= (n - m))
        t++;
      else {
        T[i][m] = aux[t];
        t++;
        m++;
      }
    }
  }

  delete [] aux;

  for (int i = 0; i < k; i++) {
   for (int j = 0; j < n; j++)
     cout << T[i][j] << " ";
   cout << " " << endl;
  }

  int* res = new int[N];
  mezclaK(T, res, n, k);
  
  delete [] T;

  cout << "\nRes: ";
  for (int i = 0; i < N; ++i)
    cout << res[i] << " ";

  delete [] res;
}
