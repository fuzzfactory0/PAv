#include "Sesion.h"
#include <list>
#include <map>


using namespace std;

Sesion* Sesion::instancia = NULL;

bool Sesion::iniciada = false;

Sesion::Sesion(){}

Sesion* Sesion::getInstancia(){
  if (instancia == NULL) instancia = new Sesion();
  return instancia;
}

void Sesion::setLogin(){
  iniciada = true;
}

void Sesion::setLogout(){
  iniciada = false;
}

bool Sesion::checkIniciada(){
  return iniciada;
}

void Sesion::setUsuario(Usuario* usr){
  this->usuario = usr;
}

string Sesion::getUsuario(){
  return this->usuario->getNickname();
}

Sesion::~Sesion(){}
