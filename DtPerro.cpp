#include "DtPerro.h"
#include <iostream>

DtPerro::DtPerro(){}
DtPerro::DtPerro(string nombre, Genero genero, float peso, RazaPerro raza, bool vacunaCachorro):DtMascota(nombre,genero,peso){
  this->raza=raza;
  this->vacunaCachorro=vacunaCachorro;
  this->racionDiaria = this->getPeso() * 0.025;
}
bool DtPerro::getVacunaCachorro(){
  return this->vacunaCachorro;
}

RazaPerro DtPerro::getRaza(){
  return this->raza;
}

ostream& operator<<(ostream& os, const DtPerro& perro){
  string raza;
  string vacuna;
  switch(perro.raza){
    case 0: raza = "Labrador"; break;
    case 1: raza = "Ovejero"; break;
    case 2: raza = "Bulldog"; break;
    case 3: raza = "Pitbull"; break;
    case 4: raza = "Collie"; break;
    case 5: raza = "Pekines"; break;
    case 6: raza = "Otro"; break;
  }
  if(perro.vacunaCachorro) vacuna = "Si"; else vacuna = "No";
  os << (DtMascota) perro << "\n- Racion Diaria: " << perro.racionDiaria << " gramos" << "\n- Raza: " << raza << "\n- Vacuna: " << vacuna << endl;
  return os;
}
void DtPerro::setRacionDiaria(){
  this->racionDiaria = this->getPeso() * 0.025;
}

DtPerro::~DtPerro(){}
