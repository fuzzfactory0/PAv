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
int Sala:getIDA(){
  return this->IDA++;
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
DtFuncion* Sala::getFuncionesPelicula(){

}
DtFuncion Sala::getFuncion(){

}
void Sala::EliminarFuncion(){

}
Sala::~Sala(){}
