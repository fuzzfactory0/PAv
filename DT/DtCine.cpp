#include "DtCine.h"

DtCine::DtCine(){}
DtCine::DtCine(int id, Direccion direccion){
  this->id = id;
  this->direccion = direccion;
}
void DtCine::setId(int id){
  this->id = id;
}
int DtCine::getId(){
  return this->id;
}
void DtCine::setDireccion(Direccion direccion){
  this->direccion = direccion;
}
Direccion DtCine::getDireccion(){
  return this->direccion;
}
DtCine::~DtCine(){}
