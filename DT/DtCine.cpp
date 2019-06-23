#include "DtCine.h"
#include "../colormod.h"

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

ostream& operator <<(ostream& salida,const DtCine& dtc){
  Color::Modifier g(Color::FG_LIGHT_GREEN);
  Color::Modifier d(Color::FG_DEFAULT);
	salida <<g<< "ID: " <<d<< dtc.id <<g<<"\t| Direccion: " <<d<< dtc.direccion;
	return salida;
}

DtCine::~DtCine(){}
