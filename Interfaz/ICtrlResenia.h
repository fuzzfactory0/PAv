#ifndef ICTRLRESENIA
#define ICTRLRESENIA

#include <string>
#include "../DT/DtPelicula.h"
using namespace std;

class ICtrlResenia{
  public:
    virtual list<string> listarTitulosPeliculas() = 0;
    virtual void seleccionarPelicula(string) = 0;
    virtual int verPuntaje() = 0;
    virtual void ingresarPuntaje(int) = 0;
    void seleccionarComentario(int) = 0;
    void responderComentario(int,string) = 0;
    void agregarComentario(string) = 0;
    DtComentario* getArbolComentarios(string = 0);
};

#endif
