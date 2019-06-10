#ifndef CTRLCINE
#define CTRLCINE

#include "../Interfaz/ICtrlCine.h"
#include "../Class/Cine.h"
#include "../Class/Sala.h"
#include "../Handler/HandlerCine.h"
#include <string>
#include <list>

using namespace std;

class CtrlCine: public ICtrlCine{
  private:
    Direccion direccion;
    list<int> capacidades;
  public:
    CtrlCine();
    void ingresarDireccion(Direccion);
    void ingresarCapacidad(int);
    void altaCine();
};

#endif
