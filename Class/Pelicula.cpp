#include "Pelicula.h"

Pelicula::Pelicula(){}

Pelicula::Pelicula(string titulo, string sinopsis, string poster){
  this->titulo = titulo;
  this->sinopsis = sinopsis;
  this->poster = poster;
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

void Pelicula::addComentario(Comentario* cmt){
  this->comentarios.push_back(cmt);
}

list<Puntaje*> Pelicula::getPuntajes(){
  list<Puntaje*> puntajes;
  for(list<Puntaje*>::iterator it =this->puntajes.begin(); it != this->puntajes.end(); ++it){
    puntajes.push_back(*it);
  }
  return puntajes;
}
/*
list<Comentario*> getComentarios(){
  return this->comentarios;
}*/

float Pelicula::getPuntajePromedio(){
  int total;
  for (list<Puntaje*>::iterator it=this->puntajes.begin(); it != this->puntajes.end(); ++it)
    total += (*it)->getPuntos();
  return total / this->puntajes.size();
}

void Pelicula::setPoster(string poster){
  this->poster = poster;
}
string Pelicula::getPoster(){
  return this->poster;
}

DtPelicula* Pelicula::getInfoPelicula(){

}

Pelicula::~Pelicula(){}
