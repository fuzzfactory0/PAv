#ifndef CINE
#define CINE

#include "Sala.h"
#include "Direccion.h"
#include "DtSala.h"

class Cine{
  private:
    static int IDA;
    int id;
    Direccion direccion;
    map<int,Sala*> salas;
  public:
    Cine();
    Cine(int,direccion);
    void setId(int);
    int getIDA();
    int getId();
    void setDireccion(direccion);
    Direccion getDireccion();
    dtSala getDtSala();
    Sala getSalaPelicula();
    void eliminarPelicula(cine,sala);
    ~Cine();
};

#endif;
