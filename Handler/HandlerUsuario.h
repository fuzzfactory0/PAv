#ifndef HANDLERUSUARIO
#define HANDLERUSUARIO

#include "../Class/Usuario.h"
#include <map>
#include <string>
#include <list>

class HandlerUsuario{
  private:
    static HandlerUsuario* instancia;
    map<string,Usuario*> usuarios;
    HandlerUsuario();
  public:
    static HandlerUsuario* getInstancia();
    list<Usuario*> getUsuarios();
    Usuario* buscarUsuario(string);
    void addUsuario(Usuario*);
    bool existeUsuario(string);
    void eliminarUsuario(string);
    virtual ~HandlerUsuario();
};
#endif
