#include "CtrlCine.h"

CtrlCine::CtrlCine(){}

// Alta pelicula
 void CtrlCine::ingresarDireccion(Direccion dir){
   this->direccion = dir;
 }

 void CtrlCine::ingresarCapacidad(int cap){
    this->capacidades.push_back(cap);
 }

 void CtrlCine::altaCine(){
   int cantidadSalas = 0, capacidad = 0;
   HandlerCine* hC = HandlerCine::getInstancia();
   Cine* c = new Cine(Cine::getIDA(),this->direccion);
   for(list<int>::iterator it = this->capacidades.begin(); it != this->capacidades.end(); ++it){
     Sala* s = new Sala(Sala::getIDA(), *it);
     c->addSala(s);
   }
   hC->addCine(c);
 }
