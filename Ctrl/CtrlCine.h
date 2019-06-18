#ifndef CTRLCINE
#define CTRLCINE
#define PRECIO_ENTRADA 30
#define PORCENTAJE_DESCUENTO 22

#include <map>
#include <list>
#include <string>

#include "../Interfaz/ICtrlCine.h"
#include "../Class/Cine.h"
#include "../Class/Sala.h"
#include "../Class/Funcion.h"
#include "../Class/Pelicula.h"
#include "../Handler/HandlerCine.h"
#include "../Handler/HandlerPelicula.h"
#include "../DT/DtCine.h"
#include "../DT/TipoPago.h"
#include "../DT/DtPelicula.h"

using namespace std;

class CtrlCine: public ICtrlCine{
  private:
    Direccion direccion;
    list<int> capacidades;
    string pelicula;
    int idCine;
    int idSala;
    int idFuncion;
    int cantidadAsientos;
    Horario hora;
    Fecha dia;
    TipoPago modoPago;
    string entePago;
  public:
    CtrlCine();
    //Funciones Multiuso
    list<string> listarTitulosPeliculas();
    DtPelicula* seleccionarPelicula(string);
    map<int,DtCine*> listarCines();
    //Funciones Crear Reserva
    list<DtFuncion*> seleccionarCineReserva(int);
    void seleccionarFuncion(int);
    void ingresarCantidadAsientos(int);
    void ingresarModoPago(TipoPago);
    void ingresarNombreBanco(string);
    float ingresarFinanciera(string);
    float verPrecioTotal();
    void confirmarReserva();
    //Funciones Alta Cine
    void ingresarDireccion(Direccion);
    void ingresarCapacidad(int);
    void altaCine();
    void cancelAltaCine();
    //Funciones Alta Funcion
    list<DtCine> listarIdCines();
    void seleccionarCineFuncion(int);
    void seleccionarSalaFuncion(int);
    void ingresarHorario(Fecha,Horario);
    void altaFuncion();
    ~CtrlCine();
};

#endif
