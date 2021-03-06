#include "DtComentario.h"

DtComentario::DtComentario(){
  this->padre = NULL;
  this->ph = NULL;
  this->sh = NULL;
}
DtComentario::DtComentario(int id, string texto, string user){  
  this->texto = texto;
  this->id = id;
  this->usuario = user;
  this->padre = NULL;
  this->ph = NULL;
  this->sh = NULL;
}

void DtComentario::setTexto(string texto){
  this->texto = texto;
}

string DtComentario::getTexto(){
  return this->texto;
}

void DtComentario::setId(int id){
  this->id = id;
}

int DtComentario::getId(){
  return this->id;
}

void DtComentario::setUsuario(string user){
  this->usuario = user;
}

string DtComentario::getUsuario(){
  return this->usuario;
}

DtComentario* DtComentario::getPadre(){
  return this->padre;
}

DtComentario* DtComentario::getPh(){
  return this->ph;
}

DtComentario* DtComentario::getSh(){
  return this->sh;
}

void DtComentario::setPh(DtComentario* ph){
  this->ph = ph;
}

void DtComentario::setSh(DtComentario* sh){
  this->sh = sh;
}

bool DtComentario::hasPh(){
  return this->ph == NULL;
}

DtComentario::~DtComentario(){}