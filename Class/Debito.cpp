#include "Debito.h"

Debito::Debito(){}
Debito::Debito(string banco){
  this->banco = banco;
}
void Debito::setBanco(string banco){
  this->banco = banco;
}
string Debito::getBanco(){
  return this->banco;
}
Debito::~Debito(){}
