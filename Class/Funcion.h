#ifndef FUNCION
#define FUNCION

#include <map>
#include <list>

#include "Pelicula.h"
#include "Reserva.h"
#include "../DT/Fecha.h"
#include "../DT/Horario.h"

using namespace std;

class Funcion{
  private:
    static int IDA;
    int id;
    Fecha fecha;
    Horario horario;
    Pelicula* pelicula;
    map<int,Reserva*> reservas;
  public:
    Funcion();
    Funcion(int,Fecha,Horario);
    void setId(int);
    int getId();
    void setFecha(Fecha);
    Fecha getFecha();
    void setHorario(Horario);
    Horario getHorario();
    static int getIDA();
    void setPelicula(Pelicula*);
    string getPelicula();
    list<Reserva*> getReservas();
    void addReserva(Reserva*);
    ~Funcion();
};

#endif
