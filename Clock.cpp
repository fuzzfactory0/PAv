#include "Clock.h"

Clock* Clock::instancia = NULL;

Clock::Clock(){}

Clock* Clock::getInstancia(){
  if(instancia == NULL){
    instancia = new Clock();
  }
  return instancia;
}

void Clock::setHorario(Horario hor){
  this->horario = hor;
}

void Clock::setFecha(Fecha fec){
  this->fecha = fec;
}

Horario Clock::getHorario(){
  return this->horario;
}

Fecha Clock::getFecha(){
  return this->fecha;
}

Clock::~Clock(){}