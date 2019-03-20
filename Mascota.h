#ifndef MASCOTA
#define MASCOTA

#include "Genero.h"

#include <iostream>
using namespace std;

class Mascota{
private:
  string nombre;
  Genero genero;
  float peso;
  float racionDiaria;
public:
  Mascota();
  Mascota(string nombre, Genero genero, float peso);
  string getNombre();
  Genero getGenero();
  float getPeso();
  float getRacionDiaria();
  void setNombre(string nombre);
  void setGenero(Genero genero);
  void setPeso(float peso);
  void setRacionDiaria(float racionDiaria);
  ~Mascota();
  virtual float obtenerRacionDiaria()=0;
};

#endif
