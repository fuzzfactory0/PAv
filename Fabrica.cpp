#include "Fabrica.h"
#include "Ctrl/CtrlUsuario.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
  if(instancia == NULL){
    instancia = new Fabrica();
  }
  return instancia;
}

ICtrlUsuario* Fabrica::getICtrlUsuario(){
  return new CtrlUsuario;
}

Fabrica :: ~Fabrica();
