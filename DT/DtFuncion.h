#ifndef DTFUNCION
#define DTFUNCION

#include "../DT/Fecha.h"
#include "../DT/Horario.h"

using namespace std;

class DtFuncion{
  private:
    int id;
    Fecha fecha;
    Horario horario;
  public:
    DtFuncion();
    DtFuncion(int,Fecha,Horario);
    void setId(int);
    int getId();
    void setFecha(Fecha);
    Fecha getFecha();
    void setHorario(Horario);
    Horario getHorario();
    ~DtFuncion();
    friend ostream& operator <<(ostream&, const DtFuncion&);
};

#endif
