#include "CtrlPelicula.h"
#include "../Handler/HandlerPelicula.h"
#include "../Class/Pelicula.h"

CtrlPelicula::CtrlPelicula(){}

list<string> CtrlPelicula::listarTitulosPeliculas(){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  list<Pelicula*> peliculas = hP->getPeliculas();
  list<string> titulos;
  for (list<Pelicula*>::iterator it=peliculas.begin(); it!=peliculas.end(); ++it)
    titulos.push_back((*it)->getTitulo());
  return titulos;
}

DtPelicula CtrlPelicula::seleccionarPelicula(string ttl){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  if (!hP->existePelicula(ttl)) throw 404;
  Pelicula* peli = hP->buscarPelicula(ttl);
  this->pelicula = peli->getTitulo();
  DtPelicula dtPelicula = DtPelicula(peli->getTitulo(), peli->getSinopsis(), peli->getPuntajePromedio(), peli->getPoster());
  return dtPelicula;
}

void CtrlPelicula::cargarPeliculas(){
  HandlerPelicula* hP = HandlerPelicula::getInstancia();
  Pelicula* p1 = new Pelicula("Fight Club","Primera regla del club de la pelea: Nunca hablar del club de la pelea","https://pics.filmaffinity.com/fight_club-320750671-large.jpg");
  hP-> addPelicula(p1);
  Pelicula* p2 = new Pelicula("Gummo","Chico conejo","https://images-na.ssl-images-amazon.com/images/I/81OVQsnj5LL._SL1293_.jpg");
  hP-> addPelicula(p2);
  Pelicula* p3 = new Pelicula("The Beach","Isla secreta","https://images-na.ssl-images-amazon.com/images/I/41S%2B7nrZgVL.jpg");
  hP-> addPelicula(p3);
  Pelicula* p4 = new Pelicula("Harold and Maude","Pendejo y vieja se enamoran(?)","https://images-na.ssl-images-amazon.com/images/I/61dVEtdthoL.jpg");
  hP-> addPelicula(p4);
  Pelicula* p5 = new Pelicula("Kids","Cuidado con el virus","https://i.ebayimg.com/images/i/272476895256-0-1/s-l1000.jpg");
  hP-> addPelicula(p5);
  Pelicula* p6 = new Pelicula("Clockwork Orange","La cura a la agresividad","https://static.posters.cz/image/750/poster/clockwork-orange-i56126.jpg");
  hP-> addPelicula(p6);
  Pelicula* p7 = new Pelicula("The Shining","All work and no play makes...","https://images-na.ssl-images-amazon.com/images/I/51g-8R5FOhL.jpg");
  hP-> addPelicula(p7);
}
CtrlPelicula::~CtrlPelicula(){}
