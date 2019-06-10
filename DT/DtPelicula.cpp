#include "DtPelicula.h"

DtPelicula::DtPelicula(){}
DtPelicula::DtPelicula(string titulo,string sinopsis,float puntajePromedio,string poster){
  this->titulo = titulo;
  this->sinopsis = sinopsis;
  this->puntajePromedio = puntajePromedio;
  this->poster = poster;
}
void DtPelicula::setTitulo(string titulo){
  this->titulo = titulo;
}
string DtPelicula::getTitulo(){
  return this->titulo;
}
void DtPelicula::setSinopsis(string sinopsis){
  this->sinopsis = sinopsis;
}
string DtPelicula::getSinopsis(){
  return this->sinopsis;
}
void DtPelicula::setPuntajePromedio(float puntajePromedio){
  this->puntajePromedio = puntajePromedio;
}
float DtPelicula::getPuntajePromedio(){
  return this->puntajePromedio;
}
void DtPelicula::setPoster(string poster){
  this->posterURL = poster;
}
string DtPelicula::getPoster(){
  return this->posterURL;
}
DtPeliula::~DtPelicula(){}
