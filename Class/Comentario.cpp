#include "Comentario.h"

int Comentario::IDA = 0;

Comentario::Comentario(){
  this->padre = NULL;
  this->ph = NULL;
  this->sh = NULL;
}

Comentario::Comentario(int id, string texto){
  this->texto = texto;
  this->id = id;
  this->padre = NULL;
  this->ph = NULL;
  this->sh = NULL;
}

void Comentario::setTexto(string texto){
  this->texto = texto;
}

string Comentario::getTexto(){
  return this->texto;
}

void Comentario::setId(int id){
  this->id = id;
}

int Comentario::getId(){
  return this->id;
}

int Comentario::getIDA(){
  IDA++;
  return IDA;
}

void Comentario::setUsuario(Usuario* user){
  this->usr = user;
}

string Comentario::getUsuario(){
  return this->usr->getNickname();
}

Comentario::~Comentario(){}

Comentario* Comentario::getPadre(){
  return this->padre;
}

Comentario* Comentario::getPh(){
  return this->ph;
}

Comentario* Comentario::getSh(){
  return this->sh;
}

void Comentario::setPh(Comentario* com){
  this->ph = com;
}

void Comentario::setSh(Comentario* com){
  this->sh = com;
}

bool Comentario::hasPh(){
  return this->ph != NULL;
}

bool Comentario::hasSh(){
  return this->sh != NULL;
}

Comentario* Comentario::buscarComentario(Comentario* raiz, int id){
  if (raiz->id == id) return raiz;
  else if (!raiz->hasPh() && !raiz->hasSh()) return NULL;
  else
  {
    Comentario* comm = NULL;
    if (raiz->hasSh()){
      comm = buscarComentario(raiz->getSh(), id);
    }
    else if (comm == NULL && raiz->hasPh()){
      comm = buscarComentario(raiz->getPh(), id);
    }
    return comm;
  } 
}

void Comentario::addComentario(Comentario* padre, Comentario* comm){
  if (!padre->hasPh()) padre->ph = comm;
  else{
    Comentario* aux = padre->getPh();
    while (aux->hasSh()) aux = aux->getSh();
    aux->sh = comm;
  }
}


