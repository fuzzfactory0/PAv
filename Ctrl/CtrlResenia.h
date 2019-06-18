#ifndef CTRLRESENIA
#define CTRLRESENIA

#include <list>
#include <string>

#include "../Interfaz/ICtrlResenia.h"
#include "../Class/Pelicula.h"
#include "../Handler/HandlerPelicula.h"
#include "../DT/DtPelicula.h"
#include "../Class/Puntaje.h"

class CtrlResenia: public ICtrlResenia{
  private:
    string pelicula;
    string nickname;
  public:
    CtrlResenia();
    list<string> listarTitulosPeliculas();
    DtPelicula* seleccionarPelicula(string pelicula);
    float verPuntaje();
    void ingresarPuntaje(float);
    ~CtrlResenia();
};
#endif
