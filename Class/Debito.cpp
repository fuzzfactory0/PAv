#include "Debito.h"

Debito::Debito(){}
Debito::Debito(int id, float costo, int cantAsientos, string banco):Reserva(id,costo,cantAsientos){
  this->banco = banco;
}
void Debito::setBanco(string banco){
  this->banco = banco;
}
string Debito::getBanco(){
  return this->banco;
}
Debito::~Debito(){}
