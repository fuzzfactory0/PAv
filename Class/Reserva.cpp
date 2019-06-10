#include "Reserva.h"

Reserva::Reserva(){}
Reserva::Reserva(float costo, int cantEntradas){
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
Reserva::~Reserva(){}
