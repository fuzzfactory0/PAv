#include "Puntaje.h"

int Puntaje::IDA = 0;

Puntaje::Puntaje(){}

Puntaje::Puntaje(int id, int puntos, Usuario* usr){
  this->id = id;
  this->puntos = puntos;
  this->usr = usr;
}

void Puntaje::setUsuario(Usuario* usr){
  this->usr = usr;
}

string Puntaje::getUsuario(){
  return this->usr->getNickname();
}

void Puntaje::setPuntos(int puntos){
  this->puntos = puntos;
}

void Puntaje::setId(int id){
  this->id = id;
}

int Puntaje::getId(){
  return this->id;
}

int Puntaje::getIDA(){
  IDA++;
  return IDA;
}

int Puntaje::getPuntos(){
  return this->puntos;
}

Puntaje::~Puntaje(){}
