#include "DtSala.h"
#include "../colormod.h"

DtSala::DtSala(){}

DtSala::DtSala(int id,int capacidad){
  this->id = id;
  this->capacidad = capacidad;
}
void DtSala::setId(int id){
  this->id = id;
}
int DtSala::getId(){
  return this->id;
}
void DtSala::setCapacidad(int capacidad){
  this->capacidad = capacidad;
}
int DtSala::getCapacidad(){
  return this->capacidad;
}

ostream& operator <<(ostream& salida,const DtSala& dts){
  Color::Modifier g(Color::FG_LIGHT_GREEN);
  Color::Modifier d(Color::FG_DEFAULT);
	salida <<g<< "ID: " <<d<< dts.id <<g<< "| Capacidad: " <<d<< dts.capacidad;
	return salida;
}

DtSala::~DtSala(){}
