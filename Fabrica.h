#ifndef FABRICA
#define FABRIRCA

#include "./Interfaz/ICtrlUsuario.h"

class Fabrica{
  private:
    static Fabrica* instancia;
    Fabrica();
  public:
    static Fabrica* getInstancia();
    static ICtrlUsuario* getICtrlUsuario();
    ~Fabrica();

};
#endif
