#include "DtFecha.h"
#include <iostream>
using namespace std;

DtFecha::DtFecha(){}

DtFecha::DtFecha(int d, int m, int a){
  this->dia=d;
  this->mes=m;
  this->anio=a;
}

int DtFecha::getDia(){
  return this->dia;
}
int DtFecha::getMes(){
  return this->mes;
}
int DtFecha::getAnio(){
  return this->anio;
}
void DtFecha::setDia(int d){
  this->dia=d;
}
void DtFecha::setMes(int m){
  this->mes=m;
}
void DtFecha::setAnio(int a){
  this->anio=a;
}

bool operator<(const DtFecha& date1, const DtFecha& date2){
    bool esMenor=false;
    if(date1.anio < date2.anio){
        esMenor=true;
    }else if (date1.anio == date2.anio){
        if (date1.mes < date2.mes){
            esMenor=true;
        }else if(date1.mes == date2.mes){
            if(date1.dia < date2.dia){
                esMenor=true;
            }
        }
    }
    return esMenor;
}

ostream& operator<<(ostream& os, const DtFecha& fecha){
  os << fecha.dia << "/" << fecha.mes << "/" << fecha.anio;
  return os;
}

DtFecha::~DtFecha(){}
