#ifndef DTFUNCION
#define DTFUNCION

#include <iostream>

#include "DtPelicula"
#include "DtReserva"
#include "../DT/Fecha.h"
#include "../DT/Horario.h"

using namespace std;

class DtFuncion{
  private:
    int id;
    Fecha dia;
    Horario horario;
  public:
    DtFuncion();
    DtFuncion(int,Fecha,Horario);
    int getId();
    Fecha getDia();
    Horario getHorario();
    DtPelicula* getFuncionesPelicula();
    DtPelicula getPelicula();
    ~DtFuncion();
};

#endif
