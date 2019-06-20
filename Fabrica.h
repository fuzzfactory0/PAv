#ifndef FABRICA
#define FABRICA

#include "Interfaz/ICtrlUsuario.h"
#include "Interfaz/ICtrlCine.h"
#include "Interfaz/ICtrlResenia.h"
#include "Interfaz/ICtrlPelicula.h"

class Fabrica{
  private:
    static Fabrica* instancia;
    Fabrica();
  public:
    static Fabrica* getInstancia();
    static ICtrlUsuario* getICtrlUsuario();
    static ICtrlCine* getICtrlCine();
    static ICtrlResenia* getICtrlResenia();
    static ICtrlPelicula* getICtrlPelicula();
    ~Fabrica();

};
#endif
