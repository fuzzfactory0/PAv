#include "CtrlUsuario.h"
#include "HandlerUsuario.h"

CtrlUsuario::CtrlUsuario(){}

void CtrlUsuario::ingresarNickname(string nickname){
  this->nickname = nickname;
}

bool CtrlUsuario::verificarPassword(string password){
  HanlderUsuario* hU = HandlerUsuario::getInstancia();
  Usuario* usr = hU->buscarUsuario(this->nickname);
  if(usr != NULL && usr->getPassword() == password){
    return true;
  }
  else
    return false;
}

void CtrlUsuario::iniciarSesion(){
  HanlderUsuario* hU = HandlerUsuario::getInstancia();
  Usuario* usr = hU->buscarUsuario(this->nickname);
  Sesion* s = Sesion::getInstancia();
  s->setUsuario(usr);
}
