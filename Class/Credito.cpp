#include "Credito.h"

Credito::Credito(){}

Credito::Credito(int id, float costo, int cantAsientos,float porcentajeDescuento, string financiera):Reserva(id,costo,cantAsientos){
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
