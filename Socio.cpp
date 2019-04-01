#include "Socio.h"

Socio::Socio(){}

Socio::Socio(string ci, string n, DtFecha fi){
  this->ci=ci;
  this->nombre=n;
  this->fechaIngreso=fi;
}
Socio::Socio(string ci, string nom){
  this->ci=ci;
  this->nombre=nom;
}

string Socio::getCi(){
  return this->ci;
}
void Socio::setCi(string ci){
  this->ci=ci;
}
string Socio::getNombre(){
  return this->nombre;
}
void Socio::setNombre(string n){
  this->nombre=n;
}
DtFecha Socio::getFechaIngreso(){
  return this->fechaIngreso;
}
void Socio::setFechaIngreso(DtFecha fi){
  this->fechaIngreso=fi;
}
void Socio::setMascota(Mascota* m){
  this->mascotas[this->topeMascota] = m;
  this->topeMascota++;
}

int Socio::getTopeConsulta(){
  return this->topeConsulta;
}

int Socio::getTopeMascota(){
  return this->topeMascota;
}

void Socio::setTopeconsulta(){
  this->topeConsulta++;
}

void Socio::setConsulta(Consulta* consulta){
  this->consultas[this->topeConsulta]=consulta;
  this->topeConsulta++;
}

/*string Socio::getMascota(int i){
  return this->mascotas[i]->getNombre();
}*/
Mascota* Socio::getMascota(int i){
  return this->mascotas[i];
}

Consulta* Socio::getConsulta(int i){
  return this->consultas[i];
}

Socio::~Socio(){}
