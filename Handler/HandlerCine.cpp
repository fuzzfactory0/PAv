#include "HandlerCine.h"

HanlderCine* HandlerCine::instancia = NULL;

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
  list<cine*> cines;
  for (map<int,Cine*>::iterator it = this->cines.begin(); it != this->cines.end(); ++it)
    cine.push_back(it->second);
  return cines;
}

void HandlerCine::AddCine(Cine* cine){
  cines.insert(std::pair<int,Usuario*>(cine->getId(), cine));
}
bool HandlerCine::existeCine(int id){
  map<int,Cine*>::iterator it = this->cines.find(id);
  return (it != this->usuarios.end());
}
void HandlerCine::addSalaCine(idCine, Sala* s){
  Cine* c = buscarCine(idCine);
  c.salas.insert(std::pair<int,Sala*>(s.getId(), s)); 
}
