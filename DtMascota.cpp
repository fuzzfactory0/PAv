#include "DtMascota.h"
#include <iostream>

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

ostream& operator<<(ostream& os, const DtMascota& pet){
  string genero;
  if(pet.genero == 0) genero = "Macho"; else genero = "Hembra";
  os << "-Datos de mascota-\nNombre: " << pet.nombre << "\nGenero: " << genero << "\nPeso: " << pet.peso;
  return os;
}

DtMascota::~DtMascota(){}
