#include "CtrlCine.h"

 void CtrlCine::ingresarDireccion(string dir){
   this->direccion = dir;
 }

 void CtrlCine::IngresarCapacidad(int cap){

   this->capacidad = cap;
 }

 void altaCine(){
   int cantidadSalas = 0, capacidad = 0;
   HandlerCine* hC = HandlerCine::getInstancia();
   Cine* c = new Cine(Cine::getIDA(),this->direccion);
   hC->addCine(c);
   cout << "Ingrese la cantidad de salas del cine: ";
   cin >> cantidadSalas;
   for(int i; i < cantidadSalas; i++){
     cout >> "\n Ingrese la capacidad de la sala: ";
     cin << capacidad;
     ingresarCapacidad(capacidad);
     Sala* s = new Sala(Sala::getIDA(), this->capacidad);
     hC->addSalaCine(c->getId(), s)
   }

 }
