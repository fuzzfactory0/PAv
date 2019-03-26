#include "DtConsulta.h"
#include "DtFecha.h"

DtConsulta::DtConsulta(){}

DtConsulta::DtConsulta(DtFecha fc, string m){
  this->fechaConsulta=fc;
  this->motivo=m;
}
DtFecha DtConsulta::getFechaConsulta(){
  return this->fechaConsulta;
}
string DtConsulta::getMotivo(){
  return this->motivo;
}
void DtConsulta::setFechaConsulta(DtFecha fc){
  this->fechaConsulta=fc;
}
void DtConsulta::setMotivo(string m){
  this->motivo=m;
}

DtConsulta::~DtConsulta(){}
