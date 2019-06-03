#ifndef CINE
#define CINE

#include "Sala.h"
#include "Direccion.h"
#include "dtSala.h"

class Cine{
  private:
    int id;
    Direccion direccion;
  public:
    Cine();
    Cine(int,direccion);
    void setId(int);
    int getId();
    void setDireccion(direccion);
    Direccion getDireccion();
    dtSala getDtSala();
    Sala getSalaPelicula();
    void eliminarPelicula(cine,sala);
    ~Cine();
};

#endif;

