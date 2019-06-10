#ifndef DTSALA
#define DTSALA

#include "DtFuncion"

class DtSala{
  private:
    int id;
    int capacidad;
  public:
    DtSala();
    DtSala(int,int);
    void setId(int);
    int getId();
    void setCapacidad(int);
    int getCapacidad();
    ~DtSala();
};

#endif
