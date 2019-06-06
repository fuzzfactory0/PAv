#include "Cine.h"

int Cine::IDA = 0;

Cine::Cine(){}
Cine::Cine(int id,Direccion direccion){
  this->id = id;
  this->direccion = direccion;
}
void Cine::setId(int id){
  this->id = id
}
int Cine::getIDA(){
    return IDA++;
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
DtSala Cine:getDtSala(){
//jeje
}
Sala Cine::getSalaPelicula(){
//jeje
}
void Cine::eliminarPelicula(){
//jeje
}
Cine::~Cine(){}
