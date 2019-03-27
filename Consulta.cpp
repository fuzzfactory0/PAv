#include "Consulta.h"

Consulta::Consulta(){}
Consulta::Consulta(DtFecha fecha, string motivo){
  this->fechaConsulta=fecha;
  this->motivo=motivo;
}
DtFecha Consulta::getFechaConsulta(){
  return this->fechaConsulta;
}
string Consulta::getMotivo(){
  return this->motivo;
}
void Consulta::setFechaConsulta(DtFecha fecha){
  this->fechaConsulta=fecha;
}
void Consulta::setMotivo(string motivo){
  this->motivo=motivo;
}
Consulta::~Consulta(){}
