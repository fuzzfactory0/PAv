#include "Fecha.h"

Fecha::Fecha(){}

Fecha::Fecha(int dia, int mes, int anio){
  this->dia = dia;
  this->mes = mes;
  this->anio = anio;
}

void Fecha::setDia(int dia){
  this->dia = dia;
}
int Fecha::getDia(){
  return this->dia;
}
void Fecha::setMes(int mes){
  this->mes = mes;
}
int Fecha::getMes(){
  return this->mes;
}
void Fecha::setAnio(int anio){
  this->anio = anio;
}
int Fecha::getAnio(){
  return this->anio;
}
ostream& operator <<(ostream& salida,const Fecha& fec){
	salida << fec.dia << "/" << fec.mes << "/" << fec.anio;
	return salida;
}

bool operator <(const Fecha& f1, const Fecha& f2){
  if (f1.anio < f2.anio) return true;
  else if ((f1.anio == f2.anio)&&(f1.mes < f2.mes)) return true;
  else if ((f1.anio == f2.anio)&&(f1.mes == f2.mes)&&(f1.dia < f2.dia)) return true;
  else return false;
}

Fecha::~Fecha(){}
