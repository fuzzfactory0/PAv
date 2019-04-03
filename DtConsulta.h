#ifndef DTCONSULTA
#define DTCONSULTA
#include <iostream>
#include "DtFecha.h"

using namespace std;

class DtConsulta{
  private:
    DtFecha fechaConsulta;
    string motivo;
  public:
    DtConsulta();
    DtConsulta(DtFecha fechaConsulta, string motivo);
    DtFecha getFechaConsulta();
    string getMotivo();
    void setFechaConsulta(DtFecha);
    void setMotivo(string);
    ~DtConsulta();
    friend ostream& operator<<(ostream& os, const DtConsulta& cons);
};

#endif
