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
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  if (!hP->existePelicula(ttl)) throw 404;
  Pelicula* peli = hP->buscarPelicula(this->pelicula);
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
  return 0;
}

void CtrlResenia::ingresarPuntaje(int puntaje){
  Puntaje* p;
  Sesion* s = Sesion::getInstancia();
  HandlerUsuario* hU = HandlerUsuario::getInstancia();
  Usuario* u = hU->buscarUsuario(s->getUsuario());
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  Pelicula* peli = hP->buscarPelicula(this->pelicula);
  list<Puntaje*> punts = peli->getPuntajes();
  bool existe = false;

  for (list<Puntaje*>::iterator it = punts.begin(); it!=punts.end(); ++it){
    if ((*it)->getUsuario() == u->getNickname()){
      existe = true;
      p = (*it);
      break;
    } 
  }
  if (existe){
    p->setPuntos(puntaje);
  }
  else{
    p = new Puntaje(Puntaje::getIDA(),puntaje,u);
    peli->addPuntaje(p);
  }
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

DtComentario* CtrlResenia::getArbolComentarios(string pelicula){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  Pelicula* peli = hP->buscarPelicula(this->pelicula);
  Comentario* arbol = peli->getComentarios();
  DtComentario* dtc = copiarArbol(arbol);
  return dtc;
}

DtComentario* CtrlResenia::copiarArbol(Comentario* raiz){
  if (raiz == NULL) return NULL;
  DtComentario* dtc;
  if (raiz->getId() == 0) dtc = new DtComentario(raiz->getId(), raiz->getTexto(), "ROOT");
  else dtc = new DtComentario(raiz->getId(), raiz->getTexto(), raiz->getUsuario());
  dtc->setPh(copiarArbol(raiz->getPh()));
  dtc->setSh(copiarArbol(raiz->getSh()));
  return dtc;
}

int CtrlResenia::getPuntajeUsuario(string user, string peli){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  Pelicula* pelicula = hP->buscarPelicula(peli);
  list<Puntaje*> punts = pelicula->getPuntajes();
  for (list<Puntaje*>::iterator it = punts.begin(); it!=punts.end(); ++it){
    if ((*it)->getUsuario() == user){
      return (*it)->getPuntos();
    }
  }
  return 0;
}

CtrlResenia::~CtrlResenia(){}