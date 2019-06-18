#ifndef PUNTAJE
#define PUNTAJE

#include "Usuario.h"

using namespace std;

class Puntaje{
  private:
    int puntos;
    int id;
    static int IDA;
    Usuario* usr;
  public:
    Puntaje();
    Puntaje(int, int, Usuario*);
    void setUsuario(Usuario*);
    string getUsuario();
    void setId(int);
    int getId();
    static int getIDA();
    void setPuntos(int);
    int getPuntos();
    ~Puntaje();
};

#endif
