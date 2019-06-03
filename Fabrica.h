#ifndef FABRICA
#define FABRICA

#include "ICtrlUsuario.h"

class Fabrica{
  private:
    static Fabrica* instancia;
    Fabrica();
  public:
    static Fabrica* getInstancia();
    static ICtrlUsuario* getCtrlUsuario();
    ~Fabrica();

};
#endif
