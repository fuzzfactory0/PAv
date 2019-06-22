#ifndef HORARIO
#define HORARIO

#include <iostream>

using namespace std;

class Horario{
private:
  int inihora;
  int inimin;
  int finhora;
  int finmin;
public:
  Horario();
  Horario(int,int,int,int);
  void setHoraComienzo(int,int);
  int getHoraComienzo();
  int getMinComienzo();
  void setHoraFin(int,int);
  int getHoraFin();
  int getMinFin();
  ~Horario();
  friend ostream& operator <<(ostream&, const Horario&);
};
#endif
