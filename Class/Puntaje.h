#ifndef PUNTAJE
#define PUNTAJE

#include <iostream>
#include "Usuario.h"

using namespace std;

class Puntaje{
  private:
    int puntos;
    Usuario* usr;
  public:
    Puntaje();
    Puntaje(int, Usuario*);
    void setUsuario(Usuario*);
    Usuario* getUsuario();
    void setPuntos(int);
    int getPuntos();
    ~Puntaje();
};

#endif
