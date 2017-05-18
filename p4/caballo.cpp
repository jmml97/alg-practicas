struct Posicion {
  int i;
  int j;
};

Posicion operator+(Posicion a, Posicion b) {
  return {a.i + b.i, a.j + b.j};
}

Posicion direcciones[8] = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2},
                        {1, -2}, {-1, 2}, {-1, -2}};

class Tablero {
  private:
    bool tablero[8][8];   // Simula tablero ajedrez (0 sin pasar / 1 pasada)
    Posicion posActual;   // Posicion actual del caballo

  public:
    Tablero() {
      posActual = {0, 0};
      for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
          tablero[i][j] = false;.
    }

    Tablero(Tablero t, Posicion pNueva) {
      posActual = pNueva;
      for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
          tablero[i][j] = t[i][j];
      tablero[posActual.i][posActual.j] = 1;
    }

    bool estaResuelto() {
      bool resuelto = true;
      for (int i = 0; resuelto && i < 8; ++i)
        for (int j = 0; resuelto && j < 8; ++j)
          resuelto = tablero[i][j];
      return resuelto;
    }

    inline Posicion getPosicion() {return posActual;}

    inline bool posValida(Posicion pos) {return pos.i < 8 && pos.i > -1 &&
      pos.j < 8 && pos.j > -1 && tablero[pos.i][pos.j] == 0}
};

class Solucion {
  private:
    ArbolGeneral<Tablero> raiz;

    void generarTableros(Iterador tabActual) {
      for (int i = 0; i < 8; ++i) {
        Posicion pNueva = direcciones[i] + tabActual*.getPosicion();
        if (tabActual*.posValida(pNueva))
        {
          Tablero nuevo = Tablero(tabActual*, pNueva);
        }
      }
    }
}
