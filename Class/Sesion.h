#ifndef SESION
#define SESION

#include "Usuario.h"

class Sesion{
  private:
    Sesion();
    Usuario* usuario;
    static Sesion* instancia;
  public:
    static Sesion* getInstancia();
    void setUsuario(Usuario);
    Usuario* getUsuario();
    ~Sesion();
};

#endif
