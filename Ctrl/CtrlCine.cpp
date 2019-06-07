#include "CtrlCine.h"

CtrlCine::CtrlCine(){}

void CtrlCine::ingresarDireccion(Direccion dir){
  this->direccion = dir;
}

void CtrlCine::ingresarCapacidad(int cap){
  this->capacidad = cap;
}

void CtrlCine::altaCine(){
  int cantidadSalas = 0, capacidad = 0;
  HandlerCine* hC = HandlerCine::getInstancia();
  Cine* c = new Cine(Cine::getIDA(),this->direccion);
  //hC->addCine(c);
  cout << "Ingrese la cantidad de salas del cine: ";
  cin >> cantidadSalas;
  for(int i = 0; i < cantidadSalas; i++){
    cout << "\n Ingrese la capacidad de la sala: ";
    cin >> this->capacidad;
    Sala* s = new Sala(Sala::getIDA(), this->capacidad);
    //ESTÁ PA ARREGLAR!!!!!!!!!
    hC->addSalaCine(c->getId(), s);
  }

}
