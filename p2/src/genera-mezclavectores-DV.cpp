#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
//#include <algorithm>
//#include <vector>

//Generador de ejemplo para el problema de mezcla de k vectores ordenados. Para obtener k vectores ordenados de forma creciente cada uno con n elementos, genera un vector de tamaño k*n con todos los enteros entre 0 y kn-1 ordenados. Se lanzan entonces k iteraciones de un algoritmo de muestreo aleatorio de tamaño n para obtener los k vectores. Están ordenados porque el algoritmo de muestreo mantiene el orden


/* Genera un número uniformemente distribuido en el
intervalo [0,1) a partir de uno de los generadores
disponibles en C */
double uniforme() {
  int t = rand();
  double f = ((double)RAND_MAX + 1.0);
  return (double) t / f;
}


/**
 * @brief Mezclar k vectores mediante el algoritmo Divide y Vencerás
 * @param T matriz con los vectores
 * @param n tamaño de los vectores
 * @param p posición    
 */
int* mezclaDV(int** T, int n, int p, int f) {
  //Caso general
  int k = (f - p) / n; //Número de vectores
  if(k > 2) {
    //Dividivimos el número de vectores que tomamos
    int p1 =  p;
    int f1 = (f - p) / 2;
    int tam1 = (f1 - p1) * n;
    int p2 = f1 + 1;
    int f2 = f;
    int tam2 = (f2 - p2) * n;
  
    //Venceremos
    //Mezclamos cada parte
    int* v1 = new int[tam1];
    int* v2 = new int[tam2];
    v1 = mezclaDV(T, n, p1, f1);
    v2 = mezclaDV(T, n, p2, f2);
    int* sol = new int[tam1+tam2]
    mezclarClasico(v1, v2, sol, tam1, tam2);
  }
  else {
    int* sol = new int[n*2]
    return mezclaClasico(T[p], T[p+1], sol, n, n); //REVIEW: comparar
  }
}

int main(int argc, char * argv[]) {
  if (argc != 3) {
    cerr << "Formato " << argv[0] << " <num_elem>" << " <num_vect>" << endl;
    return -1;
  }

  int n = atoi(argv[1]);
  int k = atoi(argv[2]);

  int **T;
  T = new int* [k];
  assert(T);

  for(int i = 0; i < k; i++)
    T[i] = new int [n];

  int N = k * n;
  int *aux = new int[N];
  assert(aux);

  srand(time(0));
  
  //genero todos los enteros entre 0 y k*n-1
  for(int j = 0; j < N; j++)
    aux[j] = j;

  //para cada uno de los k vectores se lanza el algoritmo S (sampling) de Knuth
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

  //-----------------------------------------------------------------------//
  //------------------ALGORITMO DIVIDE Y VENCERÁS--------------------------//
  //-----------------------------------------------------------------------//
  
}
