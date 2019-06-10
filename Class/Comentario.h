#ifndef COMENTARIO
#define COMENTARIO

#include <iostream>

#include "Usuario.h"

using namespace std;

class Comentario{
  private:
    string texto;
  public:
    Comentario();
    Comentario(string);
    void setTexto(string);
    string getTexto();
    ~Comentario();
};

#endif
