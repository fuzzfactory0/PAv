#ifndef ICTRLPELICULA
#define ICTRLPELICULA

#include <string>
#include <list>
#include "../DT/DtPelicula.h"
#include "../DT/DtFuncion.h"
#include "../DT/DtCine.h"

using namespace std;

class ICtrlPelicula{
  public:
    virtual list<string> listarTitulosPeliculas() = 0;
    virtual DtPelicula seleccionarPelicula(string) = 0;
    virtual void cargarPeliculas() = 0; 
};
#endif
