#ifndef DTPELICULA
#define DTPELICULA

#include <string>

using namespace std;

class DtPelicula{
private:
  string titulo;
  string sinopsis;
  float puntajePromedio;
  string poster;
public:
  DtPelicula();
  DtPelicula(string,string,float,string);
  void setTitulo(string);
  string getTitulo();
  void setSinopsis(string);
  string getSinopsis();
  void setPuntajePromedio(float);
  float getPuntajePromedio();
  void setPoster(string);
  string getPoster();
  ~DtPelicula();
};

#endif
