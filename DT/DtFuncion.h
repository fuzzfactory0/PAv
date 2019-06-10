#ifndef DTFUNCION
#define DTFUNCION

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
    void setId(int);
    int getId();
    void setDia(Fecha);
    Fecha getDia();
    void setHorario(Horario);
    Horario getHorario();
    ~DtFuncion();
};

#endif
