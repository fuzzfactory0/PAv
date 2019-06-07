#ifndef CTRLCINE
#define CTRLCINE

#include "ICtrlCine.h"
#include "Cine.h"
#include "Sala.h"
#include "HandlerCine.h"
#include <string>

using namespace std;

class CtrlCine: public ICtrlCine{
  private:
    Direccion direccion;
    int capacidad;
  public:
    CtrlCine();
    void ingresarDireccion(Direccion);
    void ingresarCapacidad(int);
    void altaCine();
};

#endif
