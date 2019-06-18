#ifndef CTRLUSUARIO
#define CTRLUSUARIO

#include <list>
#include <string>

#include "../Interfaz/ICtrlUsuario.h"
#include "../Class/Usuario.h"
#include "../Class/Puntaje.h"
#include "../Class/Comentario.h"
#include "../DT/DtPelicula.h"

class CtrlUsuario: public ICtrlUsuario{
  private:
    string nickname;
    string pelicula;
  public:
    //Iniciar sesion
    void ingresarNickname(string);
    bool verificarPassword(string);
    void iniciarSesion();
    list<string> listarTitulosPeliculas();
    DtPelicula* seleccionarPelicula(string pelicula);
    void cargarUsuarios();
    string getUsuarioSesion();
    bool checkSesion();
    CtrlUsuario();
    ~CtrlUsuario();
};
#endif
