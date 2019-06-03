#ifndef ICTRLUSUARIO
#define ICTRLUSUARIO

#include <string>

using namespace std;

class ICtrlUsuario{
  public:
    virtual void ingresarNickname(string) = 0;
    virtual bool verificarPassword(string) = 0;
    virtual void iniciarSesion() = 0;
    virtual void cargarUsuarios() = 0;
};
#endif
