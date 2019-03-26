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
int DtFecha::getMes(){
  return this->mes;
}
int DtFecha::getAnio(){
  return this->anio;
}
void DtFecha::setDia(int d){
  this->dia=d;
}
void DtFecha::setMes(int m){
  this->mes=m;
}
void DtFecha::setAnio(int a){
  this->anio=a;
}
DtFecha::~DtFecha(){}
