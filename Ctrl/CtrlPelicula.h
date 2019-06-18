#ifndef CTRLPELICULA
#define CTRLPELICULA

#include <string>
#include <list>
#include "../Interfaz/ICtrlPelicula.h"
#include "../DT/DtPelicula.h"
#include "../DT/DtFuncion.h"
#include "../Handler/HandlerPelicula.h"
#include "../Class/Pelicula.h"


using namespace std;

class CtrlPelicula: public ICtrlPelicula{
  public:
    CtrlPelicula();
    string listarTitulosPeliculas();
    DtPelicula* seleccionarPelicula(string);
    list<DtCine*> listarCines();
    DtFuncion* seleccionarCine(string);
    void cargarPeliculas();
    ~CtrlPelicula();
};
#endif
