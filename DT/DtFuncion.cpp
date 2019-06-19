#include "DtFuncion.h"

DtFuncion::DtFuncion(){}
DtFuncion::DtFuncion(int id,Fecha fecha,Horario horario){
  this->id = id;
  this->fecha = fecha;
  this->horario = horario;
}
void DtFuncion::setId(int id){
  this->id = id;
}
int DtFuncion::getId(){
  return this->id;
}
void DtFuncion::setFecha(Fecha fecha){
  this->fecha = fecha;
}
Fecha DtFuncion::getFecha(){
  return this->fecha;
}
void DtFuncion::setHorario(Horario horario){
  this->horario = horario;
}
Horario DtFuncion::getHorario(){
  return this->horario;
}

ostream& operator <<(ostream& salida,const DtFuncion& dtf){
	salida << "ID: " << dtf.id << "| Fecha: " << dtf.fecha  << "| Horario: " << dtf.horario;
	return salida;
}

DtFuncion::~DtFuncion(){}
