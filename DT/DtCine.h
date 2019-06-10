#ifndef DTCINE
#define DTCINE

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
    void setId(int);
    int getId();
    void setDireccion(Direccion);
    Direccion getDireccion();
    ~DtCine();
};

#endif
