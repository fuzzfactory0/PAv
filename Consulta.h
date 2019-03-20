#ifndef CONSULTA
#define CONSULTA
#include "DtFecha.h"

#include <iostream>
using namespace std;

class Consulta{
  private:
    DtFecha fechaConsulta;
    string motivo;
  public:
    Consulta();
    Consulta(DtFecha fecha, string motivo);
    DtFecha getFechaConsulta();
    void setFechaConsulta(DtFecha fecha);
    string getMotivo();
    void setMotivo(string motivo);
    ~Consulta();
};

#endif
