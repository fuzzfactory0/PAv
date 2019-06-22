#ifndef ICTRLRESENIA
#define ICTRLRESENIA

#include <string>
#include "../DT/DtPelicula.h"
#include "../DT/DtComentario.h"
using namespace std;

class ICtrlResenia{
  public:
    virtual list<string> listarTitulosPeliculas() = 0;
    virtual void seleccionarPelicula(string) = 0;
    virtual int verPuntaje() = 0;
    virtual void ingresarPuntaje(int) = 0;
    virtual void seleccionarComentario(int) = 0;
    virtual void responderComentario(int,string) = 0;
    virtual void agregarComentario(string) = 0;
    virtual DtComentario* getArbolComentarios(string) = 0;
    virtual int getPuntajeUsuario(string, string) = 0;
};

#endif
