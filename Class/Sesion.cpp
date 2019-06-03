#include "Sesion.h"
#include <list>
#include <map>

using namespace std;

Sesion* Sesion::instancia = NULL;

Sesion::Sesion(){}

Sesion* Sesion::getInstacia(){
  if (instanca == NULL) instancia = new Sesion();
  return instancia;
}

void Sesion::setUsuario(Usuario* usr){
  this->usuario = usr;
}

Usuario* Sesion::getUsuario(){
  return usuario;
}

Sesion::~Sesion(){}
