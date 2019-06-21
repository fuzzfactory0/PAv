#ifndef DTCOMENTARIO
#define DTCOMENTARIO

#include <string>

class Comentario{
  private:
    int id;
    string texto;
    string usr;
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
    void setUsuario();
    string getUsuario();
    ~DtComentario();
    //arbol
    DtComentario* getPadre();
    DtComentario* getPh();
    DtComentario* getSh();
    bool isLastSibling();
    bool isNotParent();
};
#endif