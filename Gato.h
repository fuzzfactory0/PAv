#ifndef GATO
#define GATO

#include "Mascota.h"
#include "TipoPelo.h"

#include <iostream>
using namespace std;

class Gato : public Mascota{
private:
  TipoPelo tipoPelo;
public:
  Gato();
  Gato(string nombre, Genero genero, float peso, TipoPelo tipoPelo);
  TipoPelo getTipoPelo();
  void setTipoPelo(TipoPelo tipoPelo);
  ~Gato();
  float obtenerRacionDiaria();
};

#endif
