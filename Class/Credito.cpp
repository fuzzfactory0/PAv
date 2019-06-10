#include "Credito.h"

Credito::Credito(){}

Credito::Credito(float porcentajeDescuento, string financiera){
  this->porcentajeDescuento = porcentajeDescuento;
  this->financiera = financiera;
}

void Credito::setPorcentajeDescuento(float porcentajeDescuento){
  this->porcentajeDescuento = porcentajeDescuento;
}

float Credito::getPorcentajeDescuento(){
  return this->porcentajeDescuento;
}

void Credito::setFinanciera(string financiera){
  this->financiera = financiera;
}

string Credito::getFinanciera(){
  return this->financiera;
}

Credito::~Credito(){}
