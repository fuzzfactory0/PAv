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
    Comentario* padre;
    Comentario* ph;
    Comentario* sh;
  public:
    Comentario();
    Comentario(int,string);
    void setId(int);
    int getId();
    static int getIDA();
    void setTexto(string);
    string getTexto();
    void setUsuario(Usuario*);
    string getUsuario();
    ~Comentario();
    //arbol
    Comentario* getPadre();
    Comentario* getPh();
    void setPh(Comentario*);
    Comentario* getSh();
    void setSh(Comentario*);
    bool hasPh();
    bool hasSh();
    static Comentario* buscarComentario(Comentario*, int);
    static void addComentario(Comentario*, Comentario*);
};

#endif
