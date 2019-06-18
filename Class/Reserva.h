#ifndef RESERVA
#define RESERVA

#include "Usuario.h"

class Reserva{
  protected:
    int id;
    static int IDA;
    float costo;
    int cantEntradas;
    Usuario* usuario;
  public:
    Reserva();
    Reserva(int,float,int);
    void setCosto(float);
    float getCosto();
    void setCantEntradas(int);
    int getCantEntradas();

    Usuario* getUsuario();
    void setUsuario(Usuario*);

    static int getIDA();

    int getId();
    void setId(int);
    ~Reserva();
};

#endif
