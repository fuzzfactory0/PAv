#ifndef RESERVA
#define RESERVA

#include "Usuario.h"

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
