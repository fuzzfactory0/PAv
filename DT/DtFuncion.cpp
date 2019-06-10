#include "DtFuncion.h"

DtFuncion::DtFuncion(){}
DtFuncion::DtFuncion(int id,Fecha dia,Horario horario){
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
void DtFuncion::setDia(Fecha dia){
  this->dia = dia;
}
Fecha DtFuncion::getDia(){
  return this->dia;
}
void DtFuncion::setHorario(Horario horario){
  this->horario = horario;
}
Horario DtFuncion::getHorario(){
  return this->horario;
}
DtFuncion::~DtFuncion(){}
