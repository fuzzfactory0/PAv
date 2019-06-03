#include "HandlerUsuario.h"

HandlerUsuario* HandlerUsuario::instancia = NULL;

HandlerUsuario::HandlerUsuario(){}

HandlerUsuario* HandlerUsuario::getInstancia(){
  if (instancia == NULL) instancia = new HandlerUsuario();
  return instancia;
}

list<Usuario*> HandlerUsuario::getUsuarios(){
  list<Usuario*> usuarios;
  for (map<string,Usuario*>::iterator it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    usuarios.push_back(it->second);
  return usuarios;
}

Usuario* HandlerUsuario::buscarUsuario(string usr){
  map<string,Usuario*>::iterator it = this->usuarios.find(usr);
  return it->second;
}

void HandlerUsuario::addUsuario(Usuario* usr){
  usuarios.insert(std::pair<string,Usuario*>(usr->getNickname(), usr));
}

bool HandlerUsuario::existeUsuario(string usr){
  map<string,Usuario*>::iterator it = this->usuarios.find(usr);
  return (it != this->usuarios.end());
}

void HandlerUsuario::eliminarUsuario(string usr){
  map<string,Usuario*>::iterator it = this->usuarios.find(usr);
  this->usuarios.erase(it);
}

HandlerUsuario::~HandlerUsuario();
