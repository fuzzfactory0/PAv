#include "Funcion.h"

int Funcion::IDA = 0;

Funcion::Funcion(){}
Funcion::Funcion(int id, Fecha fecha, Horario horario, Pelicula* peli){
  this->id = id;
  this->fecha = fecha;
  this->horario = horario;
  this->pelicula = peli;
}

void Funcion::setId(int id){
  this->id = id;
}

int Funcion::getId(){
  return this->id;
}

void Funcion::setFecha(Fecha fecha){
  this->fecha = fecha;
}

Fecha Funcion::getFecha(){
  return this->fecha;
}

void Funcion::setHorario(Horario horario){
  this->horario = horario;
}

Horario Funcion::getHorario(){
  return this->horario;
}

void Funcion::setPelicula(Pelicula* pel){
  this->pelicula = pel;
}

int Funcion::getIDA(){
  IDA++;
  return IDA;
}

Pelicula* Funcion::getPelicula(){
  return this->pelicula;
}

list<Reserva*> Funcion::getReservas(){
  list<Reserva*> reservas;
  for (map<int,Reserva*>::iterator it = this->reservas.begin(); it != this->reservas.end(); ++it)
    reservas.push_back(it->second);
  return reservas;
}

void Funcion::addReserva(Reserva* r){
  this->reservas.insert(std::pair<int,Reserva*>(r->getId(), r));
}

Funcion::~Funcion(){}
