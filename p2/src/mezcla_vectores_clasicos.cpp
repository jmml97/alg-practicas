/**
 * EJERCICIO 4: mezcla de k vectores ordenados
 *
 * Generador de ejemplo para el problema de mezcla de k vectores ordenados. Para obtener vectores
 * ordenados de forma creciente, cada uno con n elementos, se genera un vector de tamaño k*n
 * con todos los enteros entre 0 y k*n-1 ordenados.
 *
 * Se lanzan entonces k iteraciones de un algoritmo
 * de muestreo aleatorio de tamaño n para obtener los k vectores. Están ordeados porque el
 * algoritmo de muestreo mantiene el orden.
 *
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

using namespace std;

#define PRINT_VECTOR 0

/**
 * Genera un número uniformemente distribuido en el
 * intervalo [0,1)
 */
double uniforme() {
  int t = rand();
  double f = ((double) RAND_MAX + 1.0);
  return (double) t/f;
}

/**
 * Imprime el contenido de k vectores
 */
void imprimir_vector(int* T, int n) {
  for (int i = 0; i < n; i++) {
    cout << T[i] << " ";
  }
  cout << " " << endl;
}

/**
 * Copia el contenido de un vector en otro del mismo tamaño
 */
void copy(int* T1, int* T2, int n) {
  for (int i = 0; i < n; i++)
    T1[i] = T2[i];
}

/**
 * Mezcla dos vectores ordenados en un tercero
 */
void merge(int T1[], int T2[], int S[], int n1, int n2) {
  int p1 = 0, p2 = 0, p3 = 0;

  while (p1 < n1 && p2 < n2) {
    if (T1[p1] <= T2[p2]) {
      S[p3] = T1[p1];
      p1++;
    }
    else {
      S[p3] = T2[p2];
      p2++;
    }

    p3++;
  }

  while (p1 < n1) {
    S[p3++] = T1[p1++];
  }

  while (p2 < n2) {
    S[p3++] = T2[p2++];
  }
}

/**
 * Mezcla k vectores ordenados en un vector solución
 */
int* mezcla_vectores(int** T, int k, int n) {
  int* S = new int[k*n];  // Vector mezcla
  assert(S);

  if (k > 1) {
    int* aux = new int [k*n];
    assert(aux);

    // Primera mezcla
    merge(T[0], T[1], S, n, n);

    // Resto de mezclas
    for (int i = 2; i < k; i++) {
      merge(S, T[i], aux, i*n, n);
      swap(S, aux);   // Intercambiamos punteros
    }

    delete [] aux;
  }

  else {
    for (int i = 0; i < n; i++) {
      S[i] = T[0][i];
    }
  }

  return S;
}

int main(int argc, char * argv[]) {
  if (argc != 3) {
    cerr << "Formato " << argv[0] << ": <num_elem>" << " <num_vect>" << endl;
    return -1;
  }

  int n = atoi(argv[1]);  // número de elementos
  int k = atoi(argv[2]);  // número de vectores

  int** T;
  T = new int* [k];
  assert(T);

  for (int i = 0; i < k; i++)
    T[i]= new int [n];

  int N = k*n;
  int* aux = new int [N];
  assert(aux);

  // Genera todos los enteros entre 0 y k*n-1
  srand(time(0));
  for (int j = 0; j < N; j++)
    aux[j] = j;

  // Para cada uno de los k vectores se lanza el algoritmo S (sampling) de Knuth
  for (int i = 0; i < k; i++) {
    int t = 0;
    int m = 0;

    while (m < n) {
      double u = uniforme();

      if ((N - t) * u >= (n - m)) {
        t++;
      }

      else {
        T[i][m] = aux[t];
	      t++;
	      m++;
      }
    }
  }

  delete [] aux;

  #if PRINT_VECTOR
    // Imprimir los k vectores
    for (int i = 0; i < k; i++) {
      cout << "Vector " << i + 1 << ": ";
      imprimir_vector(T[i], n);
    }
  #endif

  int* S;
  clock_t t_antes = clock();
  // Mezclamos los k vectores por el algoritmo clásico
  S = mezcla_vectores(T, k, n);
  clock_t t_despues = clock();
  cout << k << " " << ((double)(t_despues - t_antes)) / CLOCKS_PER_SEC << endl;

  #if PRINT_VECTOR
    cout << endl << "Vector mezcla: ";
    imprimir_vector(S, k*n);
  #endif

  delete [] S;

  for (int i = 0; i < k; i++)
    delete [] T[i];

  delete [] T;

  return 0;
}
