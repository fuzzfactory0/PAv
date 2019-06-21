#ifndef SALA
#define SALA

#include <map>
#include "Funcion.h"

using namespace std;

class Sala{
  private:
    int id;
    static int IDA;
    int capacidad;
    map<int,Funcion*> funciones;
  public:
    Sala();
    Sala(int,int);
    void setId(int);
    int getId();
    void setCapacidad(int);
    int getCapacidad();
    static int getIDA();
    void addFuncion(Funcion*);
    list<Funcion*> getFunciones();
    bool hasPelicula(string);
    ~Sala();
};

#endif
