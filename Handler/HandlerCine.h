#ifndef HANDLERCINE
#define HANDLERCNE

#include "Cine.h"
#include <map>
#include <string>
#include <list>

class HandlerCine{
  private:
    static HandlerCine* instancia;
    map<int,Cine*> cines;
    HandlerCine();
  public:
    static HandlerCine* getInstancia();
    list<Cine*> getCine();
    Cine* buscarCine(int);
    void addCine(Cine*);
    bool existeCine(string);
    void eliminarCine(string);
    virtual ~HandlerCine();
};
#endif
