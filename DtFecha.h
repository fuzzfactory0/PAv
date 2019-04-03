#ifndef DTFECHA
#define DTFECHA

#include <iostream>
using namespace std;

class DtFecha{
  private:
    int dia;
    int mes;
    int anio;
  public:
    DtFecha();
    DtFecha(int, int, int);
    int getDia();
    int getMes();
    int getAnio();
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    ~DtFecha();

    friend bool operator<(const DtFecha& date1, const DtFecha& date2);
    friend ostream& operator<<(ostream& os, const DtFecha& fecha);
  };

#endif
