#include "Sala.h"

int Sala::IDA = 0;

Sala::Sala(){}
Sala::Sala(int id,int capacidad){
  this->id = id;
  this->capacidad = capacidad;
}
void Sala::setId(int id){
  this->id = id;
}
int Sala::getId(){
  return this->id;
}
void Sala::setCapacidad(int capacidad){
  this->capacidad = capacidad;
}
int Sala::getCapacidad(){
  return this->capacidad;
}

int Sala::getIDA(){
  IDA++;
  return IDA;
}

void Sala::addFuncion(Funcion* func){
  this->funciones.insert(std::pair<int,Funcion*>(func->getId(), func));
}

DtFuncion* Sala::getFuncionesPelicula(){

}
list<Funcion*> Sala::getFunciones(){
  list<Funcion*> funciones;
  for (map<int,Funcion*>::iterator it = this->funciones.begin(); it != this->funciones.end(); ++it)
    funciones.push_back(it->second);
  return funciones;
}

void Sala::EliminarFuncion(int idF){

}
Sala::~Sala(){}
