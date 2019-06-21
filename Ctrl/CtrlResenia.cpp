#include "CtrlResenia.h"
#include "../Class/Sesion.h"
#include "../Handler/HandlerPelicula.h"
#include "../Handler/HandlerUsuario.h"

CtrlResenia::CtrlResenia(){}

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

//Puntuar Película

int CtrlResenia::verPuntaje(){
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
void CtrlResenia::ingresarPuntaje(int puntaje){
  Sesion* s = Sesion::getInstancia();
  HandlerUsuario* hU = HandlerUsuario::getInstancia();
  Usuario* u = hU->buscarUsuario(s->getUsuario());
  Puntaje* p = new Puntaje(Puntaje::getIDA(),puntaje,u);
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  Pelicula* peli = hP->buscarPelicula(this->pelicula);
  peli->addPuntaje(p);
}

void CtrlResenia::seleccionarComentario(int id){
  this->idcom = id;
}

void CtrlResenia::responderComentario(int idcom, string texto){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  Pelicula* peli = hP->buscarPelicula(this->pelicula);
  Comentario* respond = Comentario::buscarComentario(peli->getComentarios(), idcom);

  Comentario* comm = new Comentario(Comentario::getIDA(), texto);
  Sesion* s = Sesion::getInstancia();
  HandlerUsuario* hU = HandlerUsuario::getInstancia();
  Usuario* u = hU->buscarUsuario(s->getUsuario());
  comm->setUsuario(u);

  Comentario::addComentario(respond, comm);
}

void CtrlResenia::agregarComentario(string texto){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  Pelicula* peli = hP->buscarPelicula(this->pelicula);
  Comentario* raiz = peli->getComentarios();

  Comentario* comm = new Comentario(Comentario::getIDA(), texto);
  Sesion* s = Sesion::getInstancia();
  HandlerUsuario* hU = HandlerUsuario::getInstancia();
  Usuario* u = hU->buscarUsuario(s->getUsuario());
  comm->setUsuario(u);

  Comentario::addComentario(raiz, comm);
}

DtComentario* CtrlResenia::getArbolComentarios(string){}

CtrlResenia::~CtrlResenia(){}