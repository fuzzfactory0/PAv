#ifndef FUNCION
#define FUNCION

#include "Pelicula.h"
#include "Reserva.h"
#include "../DT/Fecha.h"
#include "../DT/Horario.h"

using namespace std;

class Funcion{
  private:
    static int idA;
    int id;
    Fecha fecha;
    Horario horario;
    Pelicula* pelicula;
  public:
    Funcion();
    Funcion(int,Fecha,Horario,Pelicula*);
    void setId(int);
    int getId();
    void setFecha(Fecha);
    Fecha getFecha();
    void setHorario(Horario);
    Horario getHorario();
    static int getIdA();
    void setPelicula(Pelicula*);
    DtPelicula getPelicula();
    ~Funcion();
};

#endif
