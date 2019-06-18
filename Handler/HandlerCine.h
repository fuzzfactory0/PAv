#ifndef HANDLERCINE
#define HANDLERCINE

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
    void eliminarCine(int);
    void addSalaCine(int, Sala*);
    ~HandlerCine();
};
#endif
