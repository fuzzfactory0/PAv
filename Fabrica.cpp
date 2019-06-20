#include "Fabrica.h"
#include "Ctrl/CtrlUsuario.h"
#include "Ctrl/CtrlCine.h"
#include "Ctrl/CtrlResenia.h"
#include "Ctrl/CtrlPelicula.h"

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
ICtrlResenia* Fabrica::getICtrlResenia(){
  return new CtrlResenia;
}
ICtrlPelicula* Fabrica::getICtrlPelicula(){
  return new CtrlPelicula;
}
Fabrica :: ~Fabrica(){}
