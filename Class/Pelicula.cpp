#include "Pelicula.h"

Pelicula::Pelicula(){
  this->comentarios = new Comentario(0, "Raiz de comentarios");
}

Pelicula::Pelicula(string titulo, string sinopsis, string poster){
  this->titulo = titulo;
  this->sinopsis = sinopsis;
  this->poster = poster;
  this->comentarios = new Comentario(0, "Raiz de comentarios");
}
void Pelicula::setTitulo(string titulo){
  this->titulo = titulo;
}

string Pelicula::getTitulo(){
  return this->titulo;
}
void Pelicula::setSinopsis(string sinopsis){
  this->sinopsis = sinopsis;
}
string Pelicula::getSinopsis(){
  return this->sinopsis;
}
void Pelicula::addPuntaje(Puntaje* pnt){
  this->puntajes.push_back(pnt);
}

list<Puntaje*> Pelicula::getPuntajes(){
  list<Puntaje*> puntajes;
  for(list<Puntaje*>::iterator it =this->puntajes.begin(); it != this->puntajes.end(); ++it){
    puntajes.push_back(*it);
  }
  return puntajes;
}

Comentario* Pelicula::getComentarios(){
  return this->comentarios;
}

float Pelicula::getPuntajePromedio(){
  int total;
  if (this->puntajes.empty()) return 0;
  else{
    for (list<Puntaje*>::iterator it=this->puntajes.begin(); it != this->puntajes.end(); ++it)
      total += (*it)->getPuntos();
    return total / this->puntajes.size();
  }
}

void Pelicula::setPoster(string poster){
  this->poster = poster;
}
string Pelicula::getPoster(){
  return this->poster;
}

DtPelicula Pelicula::getInfoPelicula(){
  DtPelicula peli = DtPelicula(this->getTitulo(), this->getSinopsis(), this->getPuntajePromedio(), this->getPoster());
  return peli;
}

void Pelicula::eliminarComentarios(Comentario* comentario){
	if(comentario->hasSh()){
		eliminarComentarios(comentario->getSh());
	}
	if(comentario->hasPh()){
		eliminarComentarios(comentario->getPh());
	}
	comentario->~Comentario();
}

Pelicula::~Pelicula(){}
