#ifndef ICTRLCINE
#define ICTRLCINE


#include <string>
#include <iostream>
#include "Direccion.h"

using namespace std;

class ICtrlCine{
  public:
    virtual void ingresarDireccion(Direccion) = 0;
    virtual void ingresarCapacidad(int) = 0;
    virtual void AltaCine() = 0;
};

#endif
