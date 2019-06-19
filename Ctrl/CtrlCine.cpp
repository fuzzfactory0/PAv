#include "../Handler/HandlerPelicula.h"
#include "../Handler/HandlerCine.h"
#include "../Handler/HandlerUsuario.h"
#include "../Class/Reserva.h"
#include "../Class/Debito.h"
#include "../Class/Credito.h"
#include "../Class/Sesion.h"
#include "CtrlCine.h"

CtrlCine::CtrlCine(){}

list<string> CtrlCine::listarTitulosPeliculas(){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  list<string> titulos;
  for (list<Pelicula*>::iterator it=hP->getPeliculas().begin(); it!=hP->getPeliculas().end(); ++it)
    titulos.push_back((*it)->getTitulo());
  return titulos;
}

DtPelicula CtrlCine::seleccionarPelicula(string ttl){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  Pelicula* peli = hP->buscarPelicula(ttl);
  this->pelicula = peli->getTitulo();
  DtPelicula dtPelicula = DtPelicula(peli->getTitulo(), peli->getSinopsis(), peli->getPuntajePromedio(), peli->getPoster());
  return dtPelicula;
}

list<DtCine> CtrlCine::listarCines(){
  HandlerCine* hC = HandlerCine::getInstancia();
  list<DtCine> cinesPelicula;
  list<Cine*> cines = hC->getCines();
  for (list<Cine*>::iterator itC=cines.begin(); itC!=cines.end(); ++itC){
    list<Sala*> salas = (*itC)->getSalas();
    for (list<Sala*>::iterator itS=salas.begin(); itS!=salas.end(); ++itS){
      list<Funcion*> funciones = (*itS)->getFunciones();
      for (list<Funcion*>::iterator itF=funciones.begin(); itF!=funciones.end(); ++itF){
        Pelicula* peli = (*itF)->getPelicula();
        if (this->pelicula == peli->getTitulo()){
          DtCine dtcine = DtCine((*itC)->getId(), (*itC)->getDireccion());
          cinesPelicula.push_back(dtcine);
        }
      }
    }
  }
  return cinesPelicula;
}

list<DtFuncion> CtrlCine::seleccionarCineReserva(int idC){
  HandlerCine* hC = HandlerCine::getInstancia();
  Cine* cine = hC->buscarCine(idC);
  list<DtFuncion> funcionesPeli;
  list<Sala*> salas = cine->getSalas();
  for (list<Sala*>::iterator itS=salas.begin(); itS!=salas.end(); ++itS){
    list<Funcion*> funciones = (*itS)->getFunciones();
    for (list<Funcion*>::iterator itF=funciones.begin(); itF!=funciones.end(); ++itF){
      if ((*itF)->getPelicula()->getTitulo() == this->pelicula){
        DtFuncion funcion = DtFuncion((*itF)->getId(), (*itF)->getFecha(), (*itF)->getHorario());
        funcionesPeli.push_back(funcion);
      }
    }
  }
  return funcionesPeli;
}

void CtrlCine::seleccionarFuncion(int id){
  this->idFuncion = id;
}

void CtrlCine::ingresarCantidadAsientos(int cant){
  this->cantidadAsientos = cant;
}

void CtrlCine::ingresarModoPago(TipoPago pago){
  this->modoPago = pago;
}

void CtrlCine::ingresarNombreBanco(string banco){
  this->entePago = banco;
}

float CtrlCine::ingresarFinanciera(string financiera){
  this->entePago = financiera;
}

float CtrlCine::verPrecioTotal(){
  return PRECIO_ENTRADA * this->cantidadAsientos;
}

void CtrlCine::confirmarReserva(){
  HandlerCine* hC = HandlerCine::getInstancia();
  map<int,DtCine*> cinesPelicula;
  list<Cine*> cines = hC->getCines();
  Funcion* func;
  bool found = false;
  for (list<Cine*>::iterator itC=cines.begin(); itC!=cines.end(); ++itC){
    list<Sala*> salas = (*itC)->getSalas();
    for (list<Sala*>::iterator itS=salas.begin(); itS!=salas.end(); ++itS){
      list<Funcion*> funciones = (*itS)->getFunciones();
      for (list<Funcion*>::iterator itF=funciones.begin(); itF!=funciones.end(); ++itF){
        if ((*itF)->getId() == this->idFuncion){
          func = (*itF);
          found = true;
          break;
        }
        if (found) break;
      }
      if (found) break;
    }
    if (found) break;
  }
  if (this->modoPago == Deb){
    Debito* deb = new Debito(Reserva::getIDA(), PRECIO_ENTRADA*this->cantidadAsientos, this->cantidadAsientos, this->entePago);
    Sesion* ses = Sesion::getInstancia();
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    deb->setUsuario(hU->buscarUsuario(ses->getUsuario()));
    func->addReserva(deb);
  }
  else if (this->modoPago == Cred){
    Credito* cred = new Credito(Reserva::getIDA(), (PRECIO_ENTRADA*this->cantidadAsientos)-PRECIO_ENTRADA*this->cantidadAsientos*(PORCENTAJE_DESCUENTO/100), this->cantidadAsientos, PORCENTAJE_DESCUENTO, this->entePago);
    Sesion* ses = Sesion::getInstancia();
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    cred->setUsuario(hU->buscarUsuario(ses->getUsuario()));
    func->addReserva(cred);
  }
}

//Alta cine

void CtrlCine::ingresarDireccion(Direccion dir){
  this->direccion = dir;
}

void CtrlCine::ingresarCapacidad(int cap){
  if (cap != 0) this->capacidades.push_back(cap);
}

void CtrlCine::altaCine(){
  HandlerCine* hC = HandlerCine::getInstancia();
  Cine* c = new Cine(Cine::getIDA(),this->direccion);
  for(list<int>::iterator it = this->capacidades.begin(); it != capacidades.end(); ++it){
    Sala* s = new Sala(Sala::getIDA(), *it);
    c->addSala(s);
  }
  hC->addCine(c);
  this->capacidades.clear();
}

//Alta Funcion
list<DtCine> CtrlCine::listarIdCines(){
  HandlerCine* hC = HandlerCine::getInstancia();
  list<Cine*> cines = hC->getCines();
  list<DtCine> dtcines;
  for(list<Cine*>::iterator it = cines.begin(); it != cines.end(); ++it){
    DtCine dtc = DtCine((*it)->getId(), (*it)->getDireccion());
    dtcines.push_back(dtc);

  }
  return dtcines;
}

list<DtSala> CtrlCine::seleccionarCineFuncion(int idCine){
    this->idCine = idCine;
    list<DtSala> dtsalas;
    HandlerCine* hC = HandlerCine::getInstancia(); 
    Cine* cine = hC->buscarCine(idCine);
    list<Sala*> salas = cine->getSalas();
    for(list<Sala*>::iterator it = salas.begin(); it != salas.end; ++it){
      DtSala dts = DtSala((*it)->getId, (*it)->getCapacidad);
      dtsalas.push_back(dts);
    }
    return dtsalas;
}

void CtrlCine::seleccionarSalaFuncion(int idSala){
  this->idSala = idSala;
}

void CtrlCine::ingresarHorario(Fecha dia, Horario hora){
  this->dia = dia;
  this->hora = hora;
}

void CtrlCine::altaFuncion(){
  HandlerCine* hC = HandlerCine::getInstancia();
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  Pelicula* p = hP->buscarPelicula(this->pelicula);
  Cine* c = hC->buscarCine(this->idCine);
  list<Sala*> salasCine = c->getSalas();
  for(list<Sala*>::iterator it = salasCine.begin(); it != salasCine.end(); ++it){
    if ((*it)->getId() == this->idSala){
      Funcion* func = new Funcion(Funcion::getIDA(),this->dia,this->hora,p);
      (*it)->addFuncion(func);
    }
  }
}

CtrlCine::~CtrlCine(){}
