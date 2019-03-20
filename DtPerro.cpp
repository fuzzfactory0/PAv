#include "DtPerro.h"

DtPerro::DtPerro(){}
DtPerro::DtPerro(string nombre, Genero genero, float peso, RazaPerro raza, bool vacunaCachorro):DtMascota(nombre,genero,peso){
  this->raza=raza;
  this->vacunaCachorro=vacunaCachorro;
}

DtPerro::~DtPerro(){}

