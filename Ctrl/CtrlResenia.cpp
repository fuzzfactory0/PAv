#include "CtrlResenia.h"
#include "../Class/Pelicula.h"
#include "../Class/Sesion.h"
#include "../Handler/HandlerPelicula.h"
#include "../Handler/HandlerUsuario.h"

CtrlResenia::CtrlResenia(){}

//Puntuar Película

list<string> CtrlResenia::listarTitulosPeliculas(){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  list<string> titulos;
  for (list<Pelicula*>::iterator it=hP->getPeliculas().begin(); it!=hP->getPeliculas().end(); ++it)
    titulos.push_back((*it)->getTitulo());
  return titulos;
}

DtPelicula* CtrlResenia::seleccionarPelicula(string ttl){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  Pelicula* peli = hP->buscarPelicula(ttl);
  this->pelicula = peli->getTitulo();
  DtPelicula* dtPelicula = new DtPelicula(peli->getTitulo(), peli->getSinopsis(), peli->getPuntajePromedio(), peli->getPoster());
  return dtPelicula;
}
float CtrlResenia::verPuntaje(){
    Sesion* s = Sesion::getInstancia();
    HandlerPelicula* hP = HandlerPelicula::getInstancia();
    Pelicula* p = hP->buscarPelicula(this->pelicula);
    list<Puntaje*> puntajes = p->getPuntajes();
    for (list<Puntaje*>::iterator it= puntajes.begin(); it != puntajes.end(); ++it){
      if((*it)->getUsuario() == s->getUsuario()){
        return (*it)->getPuntos();
      }
    }
}
void CtrlResenia::ingresarPuntaje(float puntaje){
  Sesion* s = Sesion::getInstancia();
  HandlerUsuario* hU = HandlerUsuario::getInstancia();
  Usuario* u = hU->buscarUsuario(s->getUsuario());
  Puntaje* p = new Puntaje(Puntaje::getIDA(),puntaje,u);
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  Pelicula* peli = hP->buscarPelicula(this->pelicula);
  peli->addPuntaje(p);

}
CtrlResenia::~CtrlResenia(){}
