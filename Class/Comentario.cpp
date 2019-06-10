#include "Comentario.h"

Comentario::Comentario(){}

Comentario::Comentario(string texto){
  this->texto = texto;
}

void Comentario::setTexto(string texto){
  this->texto = texto;
}

string Comentario::getTexto(){
  return this->texto;
}

Comentario::~Comentario(){}
