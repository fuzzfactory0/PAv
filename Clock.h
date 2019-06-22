#ifndef CLOCK
#define CLOCK

#include "DT/Horario.h"
#include "DT/Fecha.h"

class Clock{
  private:
    static Clock* instancia;
    Horario horario;
    Fecha fecha;
    Clock();
  public:
    static Clock* getInstancia();
    void setHorario(Horario);
    Horario getHorario();
    void setFecha(Fecha);
    Fecha getFecha();
    ~Clock();
};
#endif
