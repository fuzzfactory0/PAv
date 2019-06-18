#include "HandlerCine.h"

HandlerCine* HandlerCine::instancia = NULL;

HandlerCine::HandlerCine(){}

HandlerCine* HandlerCine::getInstancia(){
  if(instancia == NULL){
    instancia = new HandlerCine();
  }
  return instancia;
}

Cine* HandlerCine::buscarCine(int id){
    map<int,Cine*>::iterator it = this->cines.find(id);
    return it->second;
  }

list<Cine*> HandlerCine::getCines(){
  list<Cine*> listacines;
  for (map<int,Cine*>::iterator it = this->cines.begin(); it != cines.end(); ++it){
    listacines.push_back(it->second);
  }
  return listacines;
}

void HandlerCine::addCine(Cine* cine){
  this->cines.insert(std::pair<int,Cine*>(cine->getId(), cine));
}

bool HandlerCine::existeCine(int id){
  map<int,Cine*>::iterator it = this->cines.find(id);
  return (it != this->cines.end());
}

void HandlerCine::eliminarCine(int id){
  map<int,Cine*>::iterator it = this->cines.find(id);
  this->cines.erase(it);
}

HandlerCine::~HandlerCine(){}
