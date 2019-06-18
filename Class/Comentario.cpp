#include "Comentario.h"

int Comentario::IDA = 0;

Comentario::Comentario(){}

Comentario::Comentario(int id, string texto){
  this->texto = texto;
  this->id = id;
}

void Comentario::setTexto(string texto){
  this->texto = texto;
}

string Comentario::getTexto(){
  return this->texto;
}

void Comentario::setId(int id){
  this->id = id;
}

int Comentario::getId(){
  return this->id;
}

int Comentario::getIDA(){
  IDA++;
  return IDA;
}

Comentario::~Comentario(){}
