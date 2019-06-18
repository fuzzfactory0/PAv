#ifndef DTCINE
#define DTCINE

#include "../DT/Direccion.h"
#include "../DT/DtSala.h"
#include <iostream>

using namespace std;

class DtCine{
  private:
    int id;
    Direccion direccion;
  public:
    DtCine();
    DtCine(int,Direccion);
    void setId(int);
    int getId();
    void setDireccion(Direccion);
    Direccion getDireccion();
    ~DtCine();
    friend ostream& operator <<(ostream&, const DtCine&);
};

#endif
