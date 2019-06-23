#include "DtPelicula.h"
#include "../colormod.h"

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
  Color::Modifier y(Color::FG_YELLOW);
  Color::Modifier g(Color::FG_LIGHT_GREEN);
  Color::Modifier d(Color::FG_DEFAULT);
	salida <<g<< "\tTitulo: \t" <<d<< dtp.titulo;
  salida <<g<< "\n\tSinopsis: \t" <<d<< dtp.sinopsis;
  salida <<g<< "\n\tPoster: \t" <<d<< dtp.poster;
  salida <<g<< "\n\tRating: \t"<<d;
  if (dtp.puntajePromedio == 0) salida << "?/10"<<y;
  else{
    salida << dtp.puntajePromedio << "/10";
    if (dtp.puntajePromedio > 8) salida << " ★★★★★";
    else if (dtp.puntajePromedio > 6) salida << " ★★★★☆";
    else if (dtp.puntajePromedio > 4) salida << " ★★★☆☆";
    else if (dtp.puntajePromedio > 2) salida << " ★★☆☆☆";
    else salida << " ★☆☆☆☆";
  }
  salida <<d;
	return salida;
}

DtPelicula::~DtPelicula(){}
