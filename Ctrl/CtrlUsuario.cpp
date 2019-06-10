#include "CtrlUsuario.h"
#include "../Handler/HandlerUsuario.h"

CtrlUsuario::CtrlUsuario(){}

//Iniciar Sesión

void CtrlUsuario::ingresarNickname(string nickname){
  this->nickname = nickname;
}

bool CtrlUsuario::verificarPassword(string password){
  HandlerUsuario* hU = HandlerUsuario::getInstancia();
  if (hU->existeUsuario(this->nickname)){
    Usuario* usr = hU->buscarUsuario(this->nickname);
    if(usr != NULL && usr->getPassword() == password){
      return true;
    }
    else
      return false;
  }
  else
    return false;
}

void CtrlUsuario::iniciarSesion(){
  HandlerUsuario* hU = HandlerUsuario::getInstancia();
  Usuario* usr = hU->buscarUsuario(this->nickname);
  Sesion* s = Sesion::getInstancia();
  s->setUsuario(usr);
}

//Puntuar Película

list<string> CtrlUsuario::listarTitulosPeliculas(){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  list<string> titulos;
  for (map<int,Pelicula*>::iterator it=hP->peliculas.begin(); it!=peliculas.end(); ++it)
    titulos.push_back(it->second);
  return titulos;
}

DtPelicula* CtrlUsuario::seleccionarPelicula(string ttl){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  Pelicula* peli = hP->buscarPelicula(ttl);
  this->pelicula = peli->getTitulo();
  DtPelicula* dtPelicula = new DtPelicula(peli->getTitulo(), peli->getSinopsis(), peli->getPuntajePromedio(), peli->getPoster());
  return dtPelicula;
}

//! ////////////////////////////////////////////////////
//! /////////////FALTA TERMINAR PUNTUAR/////////////////
//! ////////////////////////////////////////////////////

//Pruebas
void CtrlUsuario::cargarUsuarios(){
  HandlerUsuario* hU = HandlerUsuario::getInstancia();
  Usuario* u = new Usuario("bukowski","imgur.com/e4i5n3.png","password");
  hU-> addUsuario(u);
}
