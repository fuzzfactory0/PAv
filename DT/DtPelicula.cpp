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
  this->poster = poster;
}
string DtPelicula::getPoster(){
  return this->poster;
}

ostream& operator <<(ostream& salida, const DtPelicula& dtp){
	salida << "\tTitulo: \t" << dtp.titulo;
  salida << "\n\tSinopsis: \t" << dtp.sinopsis;
  salida << "\n\tPoster: \t" << dtp.poster;
  salida << "\n\tRating: \t";
  if (dtp.puntajePromedio == 0) salida << "?/10";
  else{
    salida << dtp.puntajePromedio << "/10";
    if (dtp.puntajePromedio > 8) salida << " ★★★★★";
    else if (dtp.puntajePromedio > 6) salida << " ★★★★☆";
    else if (dtp.puntajePromedio > 4) salida << " ★★★☆☆";
    else if (dtp.puntajePromedio > 2) salida << " ★★☆☆☆";
    else salida << " ★☆☆☆☆";
  }
	return salida;
}

DtPelicula::~DtPelicula(){}
