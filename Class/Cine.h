#ifndef CINE
#define CINE

#include "Sala.h"
#include "../DT/Direccion.h"
#include "../DT/DtSala.h"
\
class Cine{
  private:
    int id;
    static int idA;
    Direccion direccion;
  public:
    Cine();
    Cine(int,Direccion);
    void setId(int);
    int getId();
    void setDireccion(Direccion);
    Direccion getDireccion();
    DtSala getDtSala();
    Sala getSalaPelicula();
    static int getIdA();
    void eliminarPelicula(Cine,Sala);
    ~Cine();
};

#endif
