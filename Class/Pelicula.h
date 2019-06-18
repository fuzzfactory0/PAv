#ifndef PELICULA
#define PELICULA

#include <list>
#include "Puntaje.h"
#include "Comentario.h"
#include "../DT/DtFuncion.h"
#include "../DT/DtPelicula.h"

using namespace std;

class Pelicula{
  private:
    string titulo;
    string sinopsis;
    string poster;
    list<Puntaje*> puntajes;
    list<Comentario*> comentarios;
  public:
    Pelicula();
    Pelicula(string,string,string);
    void setTitulo(string);
    string getTitulo();
    void setSinopsis(string);
    string getSinopsis();
    float getPuntajePromedio();
    void setPoster(string);
    string getPoster();
    void addPuntaje(Puntaje*);
    list<Puntaje*> getPuntajes();
    void addComentario(Comentario*);
    list<Comentario*> getComentarios();
    DtPelicula* getInfoPelicula();
    ~Pelicula();
};

#endif
