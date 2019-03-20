#include "DtMascota.h"

DtMascotaMascota::DtMascota(){}
DtMascota::DtMascota(string nombre, Genero genero, float peso){
  this->nombre=nombre;
  this->genero=genero;
  this->peso=peso;
  this->racionDiaria=0;
}

DtMascota::~DtMascota(){}
