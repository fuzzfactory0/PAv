#ifndef COMENTARIO
#define COMENTARIO

#include "Usuario.h"

using namespace std;

class Comentario{
  private:
    static int IDA;
    int id;
    string texto;
    Usuario* usr;
  public:
    Comentario();
    Comentario(int,string);
    void setId(int);
    int getId();
    static int getIDA();
    void setTexto(string);
    string getTexto();
    ~Comentario();
};

#endif
