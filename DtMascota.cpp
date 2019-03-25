#include "DtMascota.h"

DtMascota::DtMascota(){}
DtMascota::DtMascota(string nombre, Genero genero, float peso){
  this->nombre=nombre;
  this->genero=genero;
  this->peso=peso;
  this->racionDiaria=0;
}

string DtMascota::getNombre(){
  return this->nombre;
}
Genero DtMascota::getGenero(){
  return this->genero;
}
float DtMascota::getPeso(){
  return this->peso;
}
float DtMascota::getRacionDiaria(){
  return this->racionDiaria;
}
DtMascota::~DtMascota(){}
