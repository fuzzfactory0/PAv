#ifndef FECHA
#define FECHA

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
};

#endif
