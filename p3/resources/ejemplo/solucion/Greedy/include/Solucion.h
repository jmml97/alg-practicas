#ifndef SOLUCION_H
#define SOLUCION_H

#include "Problema.h"


class Solucion
{
    public:
        Solucion(); // Construye una solución vacía, con coste 0 y sin aristas
        Solucion(const Solucion & s); // Constructor de copia

        ~Solucion(); // Destructor

        Solucion & operator=(const Solucion & s); // Operador de asignación

        /*
            Devuelve los nodos origen y destino de la arista en la posición "a"
            de la solución, o origen=-1 y destino=-1 en caso de que no exista
        */
        void getArista(int a, int &origen, int &destino);

        double getCoste(); // Devuelve el coste de la solución


        /*
            Evalúa la solución actual en el problema "p". Como resultado, se modifica
            el coste de la solución actual. El coste será -1 si hay error al evaluar.
        */
        void Evaluar(Problema p);


        /*
            Modifica la solución actual añadiendo una arista <origen, destino>
            En caso de que la arista ya exista, no se inserta.
            En caso de que la arista <destino, origen> ya exista, no se inserta.
        */
        void addArista(int origen, int destino);


        int getNumAristas(); // Devuelve el número de aristas en la solución

    private:

        /*
          La solución es un vector de Num Aristas. Las Aristas se representarán en
          el vector "Aristas[0..1][0..Num-1]. Cada columna "i" de la matriz será una
          arista, donde la componente Arista[0][i] es el nodo origen, y la componente
          Arista[1][i] es el nodo destino.

          Cada nodo se representará con un valor entero, desde 0 hasta
          p.getNumPlazas()-1, donde "p" es un objeto de la clase "Problema". Dicho nodo
          se corresponderá con la plaza "p.getNombrePlaza ( Aristas[j][i] )"
        */
        int **Aristas;
        int Num; // Número de aristas en la solución

        double coste; // Coste de la solución
};

#endif // SOLUCION_H
