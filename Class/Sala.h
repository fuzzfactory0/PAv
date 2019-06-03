#ifndef SALA
#define SALA

#include "Funcion.h"

class Sala{
  private:
    int id;
    int capacidad;
  public:
    Sala();
    Sala(int,int);
    void setId(int);
    int getId();
    void setCapacidad(int);
    int getCapacidad();
    DtFuncion* getFuncionesPelicula();
    DtFuncion getFuncion();
    void EliminarFuncion();
    ~Sala();
};

#endif;
