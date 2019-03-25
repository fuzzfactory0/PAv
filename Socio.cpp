#include "Socio.h"

Socio::Socio(){}

Socio::Socio(string ci, string n, DtFecha fi){
  this->ci=ci;
  this->nombre=n;
  this->fechaIngreso=fi;
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
int getTopeConsulta(){
  return this->topeConsulta;
}
void setTopeconsulta(){
  this->topeConsulta++;
}
int getTopeMascota(){
  return this->topeMascota;
}
void setTopeMascota(){
  this->topeMascota++;
}
Socio::~Socio(){}
//void agregarConsulta(DtConsulta);
void setMascota(DtMascota*){

}
