#ifndef CINE
#define CINE

#include <map>
#include "Sala.h"
#include "../DT/Direccion.h"
#include "../DT/DtSala.h"

class Cine{
  private:
    static int IDA;
    int id;
    Direccion direccion;
    map<int,Sala*> salas;
  public:
    Cine();
    Cine(int,Direccion);
    void setId(int);
    static int getIDA();
    int getId();
    void setDireccion(Direccion);
    Direccion getDireccion();
    ~Cine();
};

#endif
