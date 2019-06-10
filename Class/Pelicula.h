#ifndef PELICULA
#define PELICULA

#include <iostream>
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
    string posterURL;
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
    void addPuntaje(Puntaje*);
    list<Puntaje*> getPuntajes();
    void addComentario(Comentario*);
    list<Comentario*> getComentarios();
    string getPoster();
    DtPelicula* getInfoPelicula();
    ~Pelicula();
};

#endif;
