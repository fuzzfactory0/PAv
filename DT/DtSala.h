#ifndef DTSALA
#define DTSALA

#include <iostream>

#include "DtFuncion.h"

using namespace std;

class DtSala{
  private:
    int id;
    int capacidad;
  public:
    DtSala();
    DtSala(int,int);
    int getId();
    int getCapacidad();
    DtFuncion* getFuncionesPelicula();
    DtFuncion getFuncion();
    ~DtSala();
};

#endif
