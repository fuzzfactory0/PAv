#include "Funcion.h"

int Funcion::idA = 0;

Funcion::Funcion(){}
Funcion::Funcion(int id, Fecha dia, Horario horario){
  this->id = id;
  this->dia = dia;
  this->horario = horario;
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

int Funcion::getIdA(){
  idA++;
  return idA;
}

DtPelicula Funcion::getPelicula(){

}

Funcion::~Funcion(){}
