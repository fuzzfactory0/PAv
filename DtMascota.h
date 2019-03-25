#ifndef DTMASCOTA
#define DTMASCOTA

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
  DtMascota();
  DtMascota(string nombre, Genero genero, float peso);
  string getNombre();
  Genero getGenero();
  float getPeso();
  float getRacionDiaria();
  virtual ~DtMascota();
};

#endif
