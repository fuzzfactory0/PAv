#ifndef HANDLERPELICULA
#define HANDLERPELICULA

#include <map>
#include <list>
#include <string>
#include "../Class/Pelicula.h"

class HandlerPelicula{
  private:
    static HandlerPelicula* instancia;
    map<string,Pelicula*> peliculas;
    HandlerPelicula();
  public:
    static HandlerPelicula* getInstancia();
    list<Pelicula*> getPeliculas();
    Pelicula* buscarPelicula(string);
    void addPelicula(Pelicula*);
    bool existePelicula(string);
    void eliminarPelicula(string);
    virtual ~HandlerPelicula();
};

#endif
