#include "DtGato.h"

DtGato::DtGato(){}
DtGato::DtGato(string nombre, Genero genero, float peso, TipoPelo tipoPelo):DtMascota(nombre,genero,peso){
  this->tipoPelo=tipoPelo;
}

DtGato::~DtGato(){}

