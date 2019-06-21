#include "Cine.h"

int Cine::IDA = 0;

Cine::Cine(){}
Cine::Cine(int id,Direccion direccion){
  this->id = id;
  this->direccion = direccion;
}

void Cine::setId(int id){
  this->id = id;
}

int Cine::getIDA(){
  IDA++;
  return IDA;
}

int Cine::getId(){
  return this->id;
}

void Cine::setDireccion(Direccion direccion){
  this->direccion = direccion;
}

list<Sala*> Cine::getSalas(){
  list<Sala*> salas;
  for (map<int,Sala*>::iterator it = this->salas.begin(); it != this->salas.end(); ++it)
    salas.push_back(it->second);
  return salas;
}

void Cine::addSala(Sala* s){
  this->salas.insert(std::pair<int,Sala*>(s->getId(), s));
}

Direccion Cine::getDireccion(){
  return this->direccion;
}
bool Cine::hasPelicula(string ttl){
  bool has = false;
  for (map<int,Sala*>::iterator it = this->salas.begin(); it != salas.end(); ++it){
    has = (has || it->second->hasPelicula(ttl));
  }
  return has;
}

Cine::~Cine(){}
