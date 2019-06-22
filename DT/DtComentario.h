#ifndef DTCOMENTARIO
#define DTCOMENTARIO

#include <string>

using namespace std;

class DtComentario{
  private:
    int id;
    string texto;
    string usuario;
    DtComentario* padre;
    DtComentario* ph;
    DtComentario* sh;
  public:
    DtComentario();
    DtComentario(int,string,string);
    void setId(int);
    int getId();
    void setTexto(string);
    string getTexto();
    void setUsuario(string);
    string getUsuario();
    ~DtComentario();
    //arbol
    DtComentario* getPadre();
    DtComentario* getPh();
    DtComentario* getSh();
    void setPh(DtComentario*);
    void setSh(DtComentario*);
    bool hasPh();
};
#endif