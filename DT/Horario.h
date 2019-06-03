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
  void setComienzo(string);
  void setFin(string);
  string getComienzo();
  string getFin();
  ~Horario();
};

#endif
