#include "DtGato.h"
#include <iostream>

DtGato::DtGato(){}
DtGato::DtGato(string nombre, Genero genero, float peso, TipoPelo tipoPelo):DtMascota(nombre,genero,peso){
  this->tipoPelo=tipoPelo;
  this->racionDiaria = this->getPeso() * 0.015;
}
TipoPelo DtGato::getTipoPelo(){
  return this->tipoPelo;
}

ostream& operator<<(ostream& os, const DtGato& gato){
  string tipoPelo;
  switch(gato.tipoPelo){
    case 0: tipoPelo = "Corto"; break;
    case 1: tipoPelo = "Mediano"; break;
    case 2: tipoPelo = "Largo"; break;
  }
  os << (DtMascota) gato << "\n\tRacion Diaria: " << gato.racionDiaria << " gramos" << "\n\tPelo: " << tipoPelo << endl;
  return os;
}
void DtGato::setRacionDiaria(){
  this->racionDiaria = this->getPeso() * 0.015;
}

DtGato::~DtGato(){}
