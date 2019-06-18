#include "Direccion.h"

Direccion::Direccion(){}

Direccion::Direccion(string calle, int num){
  this->calle = calle;
  this->numero = num;
}

void Direccion::setCalle(string calle){
  this->calle = calle;
}

void Direccion::setNumero(int num){
  this->numero = num;
}

string Direccion::getCalle(){
  return this->calle;
}

int Direccion::getNumero(){
  return this->numero;
}

ostream& operator <<(ostream& salida,const Direccion& dir){
	salida << dir.calle << " " << dir.numero;
	return salida;
}

Direccion::~Direccion(){}
