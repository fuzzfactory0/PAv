#ifndef CTRLUSUARIO
#define CTRLUSUARIO

#include "ICtrlUsuario.h"
#include <string>

class CtrlUsuario : public ICtrlUsuario{
  private:
    string nickname;
  public:
    void ingresarNickname(string);
    bool verificarPassword(string);
    void iniciarSesion();
    void cargarUsuarios();
    CtrlUsuario();
    ~CtrlUsuario();
};
#endif
