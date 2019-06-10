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

int Cine::getIDA(){
  IDA++;
  return IDA;
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

Cine::~Cine(){}
