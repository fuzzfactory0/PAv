#ifndef DTCINE
#define DTCINE

#include <iostream>

#include "../DT/Direccion.h"
#include "../DT/DtSala.h"

using namespace std;

class DtCine{
  private:
    int id;
    Direccion direccion;
  public:
    DtCine();
    DtCine(int,Direccion);
    int getId();
    Direccion getDireccion();
    DtSala getDtSala();
    Sala getSalaPelicula();
    ~DtCine();
};

#endif
