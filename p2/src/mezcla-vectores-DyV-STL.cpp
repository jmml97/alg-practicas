/**
 * EJERCICIO 4: mezcla de k vectores ordenados
 *
 * Generador de ejemplo para el problema de mezcla de k vectores ordenados. Para obtener vectores
 * ordenados de forma creciente, cada uno con n elementos, se genera un vector de tama�o $k*n$
 * con todos los enteros entre 0 y $k*n-1$ ordenados.
 *
 * Se lanzan entonces k iteraciones de un algoritmo
 * de muestreo aleatorio de tama�o n para obtener los k vectores. Est�n ordeados porque el
 * algoritmo de muestreo mantiene el orden.
 *
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>

using namespace std;

#define PRINT_VECTOR 0

/**
 * Genera un n�mero uniformemente distribuido en el
 * intervalo [0,1)
 */
double uniforme() {
  int t = rand();
  double f = ((double) RAND_MAX + 1.0);
  return (double) t / f;
}

void imprimir_vector(int* T, int n) {
  for (int i = 0; i < n; i++) {
    cout << T[i] << " ";
  }
  cout << " " << endl;
}

/**
 * Mezcla dos vectores ordenados en un tercero.
 */
vector<int> merge(vector<int> v1, vector<int> v2) {
    vector<int> sol(v1.size() + v2.size());
    int i = 0, j = 0, k = 0;

    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            sol[k] = v1[i];
            i++;
        } else {
            sol[k] = v2[j];
            j++;
        }
        k++;
    }

    while (i < v1.size()) {
        sol[k] = v1[i];
        i++;
        k++;
    }

    while (j < v2.size()) {
        sol[k] = v2[j];
        j++;
        k++;
    }

    return sol;
}

vector<int> mezclaDV(vector<vector<int>> vectores) {

    // Casos base
    if (vectores.size() < 1) {
        vector<int> sol;
        return sol;
    } else if (vectores.size() == 1) {
        return vectores[0];
    } else if (vectores.size() == 2) {
        return merge(vectores[0], vectores[1]);
    }

    vector<vector<int>>::iterator half = vectores.begin() + vectores.size() / 2;
    vector<vector<int>> firstHalf(vectores.begin(), half), secondHalf(half + 1, vectores.end());

    // Divide
    vector<int> s1 = mezclaDV(firstHalf);
    vector<int> s2 = mezclaDV(secondHalf);

    // Vencerás
    return merge(s1, s2);
}

int main(int argc, char * argv[]) {
  if (argc != 3) {
    cerr << "Formato " << argv[0] << " <num_elem>" << " <num_vect>" << endl;
    return -1;
  }

  int n = atoi(argv[1]);  // n�mero de elementos
  int k = atoi(argv[2]);  // n�mero de vectores

  vector<vector<int>> T (k);

  for(int i = 0; i < k; i++)
      T[i] = vector<int> (n);

  int N = k * n;
  vector<int> aux (N);

  srand(time(0));

  // Genero todos los enteros entre 0 y $k*n-1$
  for(int j = 0; j < N; j++)
    aux[j] = j;

  // Para cada uno de los k vectores se lanza el algoritmo S (sampling) de Knuth
  for(int i = 0; i < k; i++) {
    int t = 0;
    int m = 0;

    while(m < n) {
      double u = uniforme();

      if((N - t) * u >= (n - m))
	t++;
      else {
        T[i][m]=aux[t];
	t++;
	m++;
      }
    }
  }

  #if PRINT_VECTOR
    // Imprimir los k vectores
    for (int i = 0; i < k; i++) {
      cout << "Vector " << i + 1 << ": ";
      imprimir_vector(T[i], n);
    }
  #endif

  vector<int> S (N);

  clock_t t_antes = clock();
  // Mezclamos los k vectores usando Divide y Vencerás
  S = mezclaDV(T);
  clock_t t_despues = clock();
  cout << k << " " << ((double)(t_despues - t_antes)) / CLOCKS_PER_SEC << endl;

  #if PRINT_VECTOR
    cout << endl << "Vector mezcla: ";
    imprimir_vector(S, k*n);
  #endif

  return 0;
}
