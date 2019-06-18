#ifndef ICTRLUSUARIO
#define ICTRLUSUARIO

#include <list>
#include <string>

#include "../DT/DtPelicula.h"

using namespace std;

class ICtrlUsuario{
  public:
    virtual void ingresarNickname(string) = 0;
    virtual bool verificarPassword(string) = 0;
    virtual void iniciarSesion() = 0;
    virtual void cargarUsuarios() = 0;
    virtual list<string> listarTitulosPeliculas() = 0;
    virtual DtPelicula* seleccionarPelicula(string pelicula) = 0;
    virtual string getUsuarioSesion() = 0;
    virtual bool checkSesion() = 0;
};
#endif
