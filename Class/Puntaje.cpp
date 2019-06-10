#include "Puntaje.h"

Puntaje::Puntaje(){}

Puntaje::Puntaje(int puntos, Usuario* usr){
  this->puntos = puntos;
  this->usr = usr;
}

void Puntaje::setUsuario(Usuario* usr){
  this->usr = usr;
}

Usuario* Puntaje::getUsuario(){
  return this->usr;
}

void Puntaje::setPuntos(int puntos){
  this->puntos = puntos;
}

int Puntaje::getPuntos(){
  return this->puntos;
}

Puntaje::~Puntaje(){}
