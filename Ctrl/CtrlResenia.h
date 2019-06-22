#ifndef CTRLRESENIA
#define CTRLRESENIA

#include <list>
#include <string>

#include "../Interfaz/ICtrlResenia.h"
#include "../Class/Pelicula.h"
#include "../Class/Puntaje.h"
#include "../Class/Comentario.h"

class CtrlResenia: public ICtrlResenia{
  private:
    string pelicula;
    string nickname;
    int idcom;
  public:
    CtrlResenia();
    list<string> listarTitulosPeliculas();
    void seleccionarPelicula(string);
    int verPuntaje();
    void ingresarPuntaje(int);
    ~CtrlResenia();
    //agregar comentario
    void seleccionarComentario(int);
    void responderComentario(int,string);
    void agregarComentario(string);
    //imprimir comentarios
    static DtComentario* copiarArbol(Comentario*);
    DtComentario* getArbolComentarios(string);
    int getPuntajeUsuario(string, string);
};
#endif
