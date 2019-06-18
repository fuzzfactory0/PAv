#include "Fabrica.h"
#include "Ctrl/CtrlUsuario.h"
#include "Ctrl/CtrlCine.h"

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

ICtrlCine* Fabrica::getICtrlCine(){
  return new CtrlCine;
}

Fabrica :: ~Fabrica(){}
