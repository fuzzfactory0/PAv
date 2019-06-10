#ifndef RESERVA
#define RESERVA

#include <iostream>

#include "Usuario.h"

using namespace std;

class Reserva{
  private:
    float costo;
    int cantEntradas;
  public:
    Reserva();
    Reserva(float,int);
    void setCosto(float);
    float getCosto();
    void setCantEntradas(int);
    int getCantEntradas();
    ~Reserva();
};

#endif
