#include "Horario.h"

Horario::Horario(){}

Horario::Horario(string horaComienzo, string horaFin){
  this->horaComienzo = horaComienzo;
  this->horaFin = horaFin;
}
void Horario::setHoraComienzo(string horaComienzo){
  this->horaComienzo = horaComienzo;
}
string Horario::getHoraComienzo(){
  return this->horaComienzo;
}
void Horario::setHoraFin(string horaFin){
  this->horaFin = horaFin;
}
string Horario::getHoraFin(){
  return this->horaFin;
}
ostream& operator <<(ostream& salida,const Horario& hor){
	salida << "Hora inicio: " << hor.horaComienzo << "| Hora fin: " << hor.horaFin;
	return salida;
}
Horario::~Horario(){}
