#ifndef HORARIO
#define HORARIO

#include <string>

using namespace std;

class Horario{
private:
  string horaComienzo;
  string horaFin;
public:
  Horario();
  Horario(string, string);
  void setHoraComienzo(string);
  string getHoraComienzo();
  void setHoraFin(string);
  string getHoraFin();
  ~Horario();
};
#endif
