#include "Mascota.h"

Mascota::Mascota(){}
Mascota::Mascota(string nombre, Genero genero, float peso){
  this->nombre=nombre;
  this->genero=genero;
  this->peso=peso;
  this->racionDiaria=0;
}
string Mascota::getNombre(){
  return this->nombre;
}
Genero Mascota::getGenero(){
  return this->genero;
}
float Mascota::getPeso(){
  return this->peso;
}
float Mascota::getRacionDiaria(){
  return this->racionDiaria;
}
void Mascota::setNombre(string nombre){
  this->nombre=nombre;
}
void Mascota::setGenero(Genero genero){
  this->genero=genero;
}
void Mascota::setPeso(float peso){
  this->peso=peso;
}
void Mascota::setRacionDiaria(float racionDiaria){
  this->racionDiaria=0;
}
Mascota::~Mascota(){}
