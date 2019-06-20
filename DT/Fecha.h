#ifndef FECHA
#define FECHA

#include <iostream>

using namespace std;

class Fecha{
private:
  int dia;
  int mes;
  int anio;
public:
  Fecha();
  Fecha(int, int, int);
  void setDia(int);
  void setMes(int);
  void setAnio(int);
  int getDia();
  int getMes();
  int getAnio();
  ~Fecha();
  friend ostream& operator <<(ostream&, const Fecha&);
};

#endif
