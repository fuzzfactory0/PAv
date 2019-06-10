#include "Cine.h"

int Cine::idA = 0;

Cine::Cine(){}
Cine::Cine(int id,Direccion direccion){
  this->id = id;
  this->direccion = direccion;
}

void Cine::setId(int id){
  this->id = id;
}

int Cine::getId(){
  return this->id;
}

void Cine::setDireccion(Direccion direccion){
  this->direccion = direccion;
}

Direccion Cine::getDireccion(){
  return this->direccion;
}

DtSala Cine::getDtSala(){

}

Sala Cine::getSalaPelicula(){

}

int Cine::getIdA(){
  idA++;
  return idA;
}

void Cine::eliminarPelicula(Cine cine, Sala sala){

}

Cine::~Cine(){}
