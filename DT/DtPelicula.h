#ifndef DTPELICULA
#define DTPELICULA

#include <string>

using namespace std;

class DtPelicula{
private:
  string titulo;
  string sinopsis;
  float puntajePromedio;
  string posterURL;
public:
  DtPelicula();
  DtPeliula(string,string,float,string);
  void setTitulo(string);
  string getTitulo();
  void setSinopsis(string);
  string getSinopsis();
  void setPuntajePromedio(float);
  float getPuntajePromedio();
  void setPoster(string);
  string getPoster();
};

#endif
