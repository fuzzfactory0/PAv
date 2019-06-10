#ifndef SALA
#define SALA

#include <map>
#include "Funcion.h"

using namespace std;

class Sala{
  private:
    int id;
    static int idA;
    int capacidad;
    map<int,Funcion*> funciones;
  public:
    Sala();
    Sala(int,int);
    void setId(int);
    int getId();
    void setCapacidad(int);
    int getCapacidad();
    static int getIdA();
    void addFuncion(Funcion*);

    DtFuncion* getFuncionesPelicula();
    DtFuncion getFuncion();
    void EliminarFuncion(DtSala);
    ~Sala();
};

#endif
