#include "CtrlResenia.h"
#include "../Class/Pelicula.h"
#include "../Class/Sesion.h"
#include "../Handler/HandlerPelicula.h"
#include "../Handler/HandlerUsuario.h"

CtrlResenia::CtrlResenia(){}

//Puntuar Película

list<string> CtrlResenia::listarTitulosPeliculas(){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  list<Pelicula*> peliculas = hP->getPeliculas();
  list<string> titulos;
  for (list<Pelicula*>::iterator it=peliculas.begin(); it!=peliculas.end(); ++it)
    titulos.push_back((*it)->getTitulo());
  return titulos;
}

void CtrlResenia::seleccionarPelicula(string ttl){
  this->pelicula = ttl;
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
