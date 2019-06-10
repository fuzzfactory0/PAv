#ifndef CINE
#define CINE

#include "Sala.h"
#include "../DT/Direccion.h"
#include "../DT/DtSala.h"

class Cine{
  private:
    int id;
    static int idA;
    Direccion direccion;
  public:
    Cine();
    Cine(int,direccion);
    void setId(int);
    int getId();
    void setDireccion(direccion);
    Direccion getDireccion();
    DtSala getDtSala();
    Sala getSalaPelicula();
    static int getIdA();
    void eliminarPelicula(cine,sala);
    ~Cine();
};

#endif
