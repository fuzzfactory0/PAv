#ifndef CTRLCINE
#define CTRLCINE

#include "ICtrlCine.h"
#include "Cine.h"
#include "HandlerCine"
#include <string>

using namespace std;

class CtrlCine: public ICtrlCine{
  private:
    string direccion;
    int capacidad;
  public:
    void ingresarDireccion(string);
    void ingresarCapacidad(int);
    void AltaCine();
};

#endif
