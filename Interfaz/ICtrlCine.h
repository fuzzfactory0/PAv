#ifndef ICTRLCINE
#define ICTRLCINE

#include <map>
#include <list>
#include <string>
#include "../DT/Direccion.h"
#include "../DT/DtCine.h"
#include "../DT/TipoPago.h"
#include "../DT/DtFuncion.h"
#include "../DT/DtPelicula.h"

using namespace std;

class ICtrlCine{
  public:
    virtual list<string> listarTitulosPeliculas() = 0;
    virtual DtPelicula seleccionarPelicula(string) = 0;
    virtual list<DtCine> listarCines() = 0;
    //Funciones Crear Reserva
    virtual list<DtFuncion> seleccionarCineReserva(int) = 0;
    virtual void seleccionarFuncion(int) = 0;
    virtual void ingresarCantidadAsientos(int) = 0;
    virtual void ingresarModoPago(TipoPago) = 0;
    virtual void ingresarNombreBanco(string) = 0;
    virtual float ingresarFinanciera(string) = 0;
    virtual float verPrecioTotal() = 0;
    virtual void confirmarReserva() = 0;
    //Funciones Alta Cine
    virtual void ingresarDireccion(Direccion) = 0;
    virtual void ingresarCapacidad(int) = 0;
    virtual void altaCine() = 0;
    //Funciones Alta Funcion
    virtual list<DtCine> listarIdCines() = 0;
    virtual list<DtSala> seleccionarCineFuncion(int) = 0;
    virtual void seleccionarSalaFuncion(int) = 0;
    virtual void ingresarHorario(Fecha,Horario) = 0;
    virtual void altaFuncion() = 0;
};

#endif
