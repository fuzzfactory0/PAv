#ifndef DTSALA
#define DTSALA

#include <iostream>

using namespace std;

class DtSala{
  private:
    int id;
    int capacidad;
  public:
    DtSala();
    DtSala(int,int);
    void setId(int);
    int getId();
    void setCapacidad(int);
    int getCapacidad();
    ~DtSala();
    friend ostream& operator <<(ostream&, const DtSala&);
};
#endif
