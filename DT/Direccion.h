#ifndef DIRECCION
#define DIRECCION

#include <string>

using namespace std;

class Direccion{
private:
  string calle;
  int numero;
public:
  Direccion();
  Direccion(string, int);
  void setCalle(string);
  void setNumero(int):
  string getCalle();
  int getNumero();
  ~Direccion();
};

#endif
