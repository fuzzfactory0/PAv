#ifndef SESION
#define SESION

#include "Usuario.h"
#include <string>

using namespace std;

class Sesion{
  private:
    Sesion();
    Usuario* usuario;
    static Sesion* instancia;
    static bool iniciada;
  public:
    static Sesion* getInstancia();
    static bool checkIniciada();
    static void setLogin();
    static void setLogout();
    void setUsuario(Usuario*);
    string getUsuario();
    ~Sesion();
};

#endif
