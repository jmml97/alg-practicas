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
//#include <algorithm>
//#include <vector>


using namespace std;

/**
 * Genera un número uniformemente distribuido en el
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
 * @brief Mezclar k vectores mediante el algoritmo Divide y Vencerás
 * @param T matriz con los vectores
 * @param n tamaño de los vectores
 * @param p posición inicial del vector en la matriz T 
 * @param f posición final del vector en la matriz T
 */
int* mezclaDV(int** T, int n, int p, int f) {
  //Caso general
  int k = (f - p + 1) / n; //Número de vectores
  if(k > 2) {
    //Dividivimos el número de vectores que tomamos
    int p1 =  p;  
    int f1 = (f - p) / 2; 
    f1 += f1 % n; // Queremos coger vectores enteros
    int tam1 = f1 - p1 + 1;
    int p2 = f1 + 1;
    int f2 = f;
    int tam2 = (f2 - p2) * n;
  
    //Mezclamos cada parte
    int* v1 = new int[tam1];
    int* v2 = new int[tam2];
    v1 = mezclaDV(T, n, p1, f1);
    v2 = mezclaDV(T, n, p2, f2);
    int* sol = new int[tam1+tam2];
    merge(v1, v2, sol, tam1, tam2);
    return sol;
  }
  else {
    if (k == 2) {
      int* sol = new int[n*2];
      merge(T[p], T[p+1], sol, n, n);
      return sol;
    }
    else //k = 1
      return T[p%k];
  }
}

int main(int argc, char * argv[]) {
  if (argc != 3) {
    cerr << "Formato " << argv[0] << " <num_elem>" << " <num_vect>" << endl;
    return -1;
  }

  int n = atoi(argv[1]);  // número de elementos
  int k = atoi(argv[2]);  // número de vectores

  int** T;
  T = new int* [k];
  assert(T);

  for(int i = 0; i < k; i++)
    T[i] = new int [n];

  int N = k * n;
  int* aux = new int[N];
  assert(aux);

  srand(time(0));
  
  // Genero todos los enteros entre 0 y k*n-1
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

  delete [] aux;
  
  cout << "Vectores sin ordenar:" << endl; 
  
  for(int i = 0; i < k; i++) {
    for(int j = 0; j < n; j++)
      cout << T[i][j] << " ";
    cout << " " << endl;
  }

  // Mezcla de k vectores
  int* S = new int [N];
  assert(S);
  
  // Mezclamos los k vectores por el algoritmo divide y vencerás
  S = mezclaDV(T, n, 0, N-1);

  cout << endl << "Vector mezcla: ";
  imprimir_vector(S, k*n);

  return 0;
}
