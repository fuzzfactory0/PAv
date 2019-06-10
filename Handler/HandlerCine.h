#ifndef HANDLERCINE
#define HANDLERCNE

#include "../Class/Cine.h"
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
    list<Cine*> getCines();
    Cine* buscarCine(int);
    void addCine(Cine*);
    bool existeCine(int);
    void eliminarCine(string);
    void addSalaCine(int, Sala*);
    virtual ~HandlerCine();
};
#endif
