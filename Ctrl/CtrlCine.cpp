#include "../Handler/HandlerPelicula.h"
#include "../Handler/HandlerCine.h"
#include "CtrlCine.h"

CtrlCine::CtrlCine(){}

list<string> CtrlCine::listarTitulosPeliculas(){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  list<string> titulos;
  for (map<int,Pelicula*>::iterator it=hP->peliculas.begin(); it!=peliculas.end(); ++it)
    titulos.push_back(it->second);
  return titulos;
}

DtPelicula* CtrlCine::seleccionarPelicula(string ttl){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  Pelicula* peli = hP->buscarPelicula(ttl);
  this->pelicula = peli->getTitulo();
  DtPelicula* dtPelicula = new DtPelicula(peli->getTitulo(), peli->getSinopsis(), peli->getPuntajePromedio(), peli->getPoster());
  return dtPelicula;
}

map<int,DtCine*> CtrlCine::listarCines(){
  HandlerCine* hC = HandlerCine::getInstancia();
  map<int,DtCine*> cines;
  for (map<int,Cine*>::iterator itC=hC->cines.begin(); itC!=cines.end(); ++itC){
    for (map<int,Sala*>::iterator itS=itC->second->salas.begin(); itS!=salas.end(); ++itS){
      for (map<int,Funcion*>::iterator itF=itS->second->funciones.begin(); itF!=funciones.end(); ++itF){
        if (this->pelicula == itF->pelicula->getTitulo() && cines.find(itC->first) == cines.end()){
          DtCine* dtcine = new DtCine(itC->first, itC->second->getDireccion());
          cines.insert(std::pair<int,DtCine*>(dtcine->getId(), dtcine));
        }
      }
    }
  }
  return cines;
}

list<DtFuncion*> CtrlCine::seleccionarCineReserva(int idC){
  HandlerCine* hC = HandlerCine::getInstancia();
  Cine* cine = hC->cines->find(idC)->second;
  list<DtFuncion*> funciones;
  for (map<int,Sala*>::iterator itS=itC->second->salas.begin(); itS!=salas.end(); ++itS){
    for (map<int,Funcion*>::iterator itF=itS->second->funciones.begin(); itF!=funciones.end(); ++itF){
      if (itF->second->pelicula->getTitulo() == this->pelicula){
        DtFuncion* funcion = new DtFuncion(itF->second->getId(), itF->second->getFecha(), itF->second->getHorario());
        funciones.push_back(funcion);
      }
    }
  }
  return funciones;
}

void CtrlCine::seleccionarFuncion(int id){
  this->idFuncion = id;
}

void CtrlCine::ingresarCantidadAsientos(int cant){
  this->cantidadAsientos = cant;
}

//! /////////////////////////////////////////////////////////////////////////////////
//! //////////////////////////FALTAN FUNCIONES///////////////////////////////////////
//! /////////////////////////////////////////////////////////////////////////////////
void CtrlCine::ingresarModoPago(TipoPago){}
void CtrlCine::ingresarNombreBanco(string){}
float CtrlCine::ingresarFinanciera(string){}
float CtrlCine::verPrecioTotal(){}
void CtrlCine::confirmarReserva(){}

//Alta cine

void CtrlCine::ingresarDireccion(Direccion dir){
  this->direccion = dir;
}

void CtrlCine::ingresarCapacidad(int cap){
  this->capacidad = cap;
}

void CtrlCine::altaCine(){
  int cantidadSalas = 0, capacidad = 0;
  HandlerCine* hC = HandlerCine::getInstancia();
  Cine* c = new Cine(Cine::getIDA(),this->direccion);
  for(list<int>::iterator it = this->capacidades.begin(); it != this->capacidades.end(); ++it){
    Sala* s = new Sala(Sala::getIDA(), *it);
    c->addSala(s);
  }
  hC->addCine(c);
}

//Alta Funcion

void CtrlCine::seleccionarCineFuncion(int idCine){
    this->idCine = idCine;
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
  Pelicula p* = buscarPelicula(this->pelicula);
  Cine c* = hC->buscarCine(this->idCine);
  map<int,Sala*>::iterator it = c->salas.find(this->idSala);
  if(it->second != NULL){
    Funcion* f = new Funcion(Funcion::getIDA(),this->dia,this->hora,p);
    it->second->funciones.insert(std::pair<int,Funcion*>(f->getId(),f));
  }
}

CtrlCine::~CtrlCine(){}