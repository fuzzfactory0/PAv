#include "Horario.h"

Horario::Horario(){}

Horario::Horario(int horai, int mini, int horaf, int minf){
  this->inihora = horai;
  this->inimin = mini;
  this->finhora = horaf;
  this->finmin = minf;
}
void Horario::setHoraComienzo(int hora, int min){
  this->inihora = hora;
  this->inimin = min;
}

int Horario::getHoraComienzo(){
  return this->inihora;
}
int Horario::getMinComienzo(){
  return this->inimin;
}
void Horario::setHoraFin(int hora, int min){
  this->finhora = hora;
  this->finmin = min;
}
int Horario::getHoraFin(){
  return this->finhora;
}
int Horario::getMinFin(){
  return this->finmin;
}

ostream& operator <<(ostream& salida,const Horario& hor){
  if(hor.inihora<10) salida << "0";
  salida << hor.inihora<<":";
  if(hor.inimin<10) salida << "0";
  salida << hor.inimin<<" - ";
  if(hor.finhora<10) salida << "0";
  salida << hor.finhora<<":";
  if(hor.finmin<10) salida << "0";
  salida << hor.finmin;
	return salida;
}
Horario::~Horario(){}
