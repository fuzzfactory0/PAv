#ifndef DTMASCOTA
#define DTMASCOTAMASCOTA

#include "Genero.h"

#include <iostream>
using namespace std;

class DtMascota{
private:
  string nombre;
  Genero genero;
  float peso;
  float racionDiaria;
public:
  DtMascotaMascota();
  DtMascotaMascota(string nombre, Genero genero, float peso);
  ~DtMascota();
};

#endif
