#ifndef CREDITO
#define CREDITO

#include <iostream.h>

#include "Reserva.h"

using namespace std;

class Credito: public Reserva{
  private:
    float porcentajeDescuento;
    string financiera;
  public:
    Credito();
    Credito(float,string);
    void setPorcentajeDescuento(float);
    float getPorcentajeDescuento();
    void setFinanciera(string);
    string getFinanciera();
    ~Credito();
};

#endif;
