#include "DtFecha.h"

DtFecha::DtFecha(){}

DtFecha::DtFecha(int d, int m, int a){
  this->dia=d;
  this->mes=m;
  this->anio=a;
}

int DtFecha::getDia(){
  return this->dia;
}
void DtFecha::setDia(int d){
  this->dia=d;
}
int DtFecha::getMes(){
  return this->mes;
}
void DtFecha::setMes(int m){
  this->mes=m;
}
int DtFecha::getAnio(){
  return this->anio;
}
void DtFecha::setAnio(int a){
  this->anio=a;
}
DtFecha::~DtFecha(){}
