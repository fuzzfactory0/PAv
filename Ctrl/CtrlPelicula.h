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
private:
   string pelicula;

  public:
    CtrlPelicula();
    list<string> listarTitulosPeliculas();
    DtPelicula seleccionarPelicula(string ttl);
    list<DtCine*> listarCines();
    DtFuncion* seleccionarCine(string);
    void cargarPeliculas();
    void eliminarPelicula();
    ~CtrlPelicula();
};
#endif
