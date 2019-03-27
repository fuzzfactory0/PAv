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
    Consulta(string motivo);//PRUEBA
    Consulta(DtFecha fecha, string motivo);
    DtFecha getFechaConsulta();
    string getMotivo();
    void setFechaConsulta(DtFecha fecha);
    void setMotivo(string motivo);
    ~Consulta();
};

#endif
