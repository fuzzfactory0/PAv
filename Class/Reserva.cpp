#include "Reserva.h"

int Reserva::IDA = 0;

Reserva::Reserva(){}
Reserva::Reserva(int id, float costo, int cantEntradas){
  this->id = id;
  this->costo = costo;
  this->cantEntradas = cantEntradas;
}
void Reserva::setCosto(float costo){
    this->costo = costo;
}
float Reserva::getCosto(){
  return this->costo;
}
void Reserva::setCantEntradas(int cantEntradas){
  this->cantEntradas = cantEntradas;
}
int Reserva::getCantEntradas(){
  return this->cantEntradas;
}

void Reserva::setId(int id){
  this->id = id;
}

int Reserva::getId(){
  return this->id;
}

Usuario* Reserva::getUsuario(){
  return this->usuario;
}

void Reserva::setUsuario(Usuario* usr){
  this->usuario = usr;
}

int Reserva::getIDA(){
  IDA++;
  return IDA;
}

Reserva::~Reserva(){}
