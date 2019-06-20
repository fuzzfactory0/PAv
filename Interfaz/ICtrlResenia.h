#ifndef ICTRLRESENIA
#define ICTRLRESENIA

#include <string>
#include "../DT/DtPelicula.h"
using namespace std;

class ICtrlResenia{
  public:
    virtual list<string> listarTitulosPeliculas() = 0;
    virtual void seleccionarPelicula(string) = 0;
    virtual float verPuntaje() = 0;
    virtual void ingresarPuntaje(float) = 0;
};

#endif
