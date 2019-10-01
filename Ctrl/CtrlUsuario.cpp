#include "CtrlUsuario.h"
#include "../Class/Sesion.h"
#include "../Class/Pelicula.h"
#include "../Handler/HandlerUsuario.h"
#include "../Handler/HandlerPelicula.h"

CtrlUsuario::CtrlUsuario(){}

bool CtrlUsuario::checkSesion(){
  return Sesion::checkIniciada();
}

string CtrlUsuario::getUsuarioSesion(){
  Sesion* ses = Sesion::getInstancia();
  return ses->getUsuario();
}

bool CtrlUsuario::checkSesionAdmin(){
  Sesion* ses = Sesion::getInstancia();
  if (!Sesion::checkIniciada()) return true;
  HandlerUsuario* hU = HandlerUsuario::getInstancia();
  Usuario* usr = hU->buscarUsuario(ses->getUsuario());
  return usr->getAdmin();
}

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
  Sesion::setLogin();
}

list<string> CtrlUsuario::listarTitulosPeliculas(){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  list<string> titulos;
  for (list<Pelicula*>::iterator it=hP->getPeliculas().begin(); it!=hP->getPeliculas().end(); ++it)
    titulos.push_back((*it)->getTitulo());
  return titulos;
}

DtPelicula* CtrlUsuario::seleccionarPelicula(string ttl){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  Pelicula* peli = hP->buscarPelicula(ttl);
  this->pelicula = peli->getTitulo();
  DtPelicula* dtPelicula = new DtPelicula(peli->getTitulo(), peli->getSinopsis(), peli->getPuntajePromedio(), peli->getPoster());
  return dtPelicula;
}

void CtrlUsuario::cargarUsuarios(){
  HandlerUsuario* hU = HandlerUsuario::getInstancia();
  Usuario* u1 = new Usuario("admin1","imgur.com/e4i5n3.png","passa1", true);
  hU-> addUsuario(u1);
  Usuario* u2 = new Usuario("user1","imgur.com/e4i5n3.png","passu1", false);
  hU-> addUsuario(u2);
  Usuario* u3 = new Usuario("admin2","imgur.com/e4i5n3.png","passa2", true);
  hU-> addUsuario(u3);
  Usuario* u4 = new Usuario("user2","imgur.com/e4i5n3.png","passu2", false);
  hU-> addUsuario(u4);
  Usuario* u5 = new Usuario("user3","imgur.com/e4i5n3.png","passu3", false);
  hU-> addUsuario(u5);
  Usuario* u6 = new Usuario("user4","imgur.com/e4i5n3.png","passu4", false);
  hU-> addUsuario(u6);
}
