#ifndef FABRICA
#define FABRICA

#include "Interfaz/ICtrlUsuario.h"
#include "Interfaz/ICtrlCine.h"

class Fabrica{
  private:
    static Fabrica* instancia;
    Fabrica();
  public:
    static Fabrica* getInstancia();
    static ICtrlUsuario* getICtrlUsuario();
    static ICtrlCine* getICtrlCine();
    ~Fabrica();

};
#endif
