#ifndef ICTRLCINE
#define ICTRLCINE


#include <string>

using namespace std;

class ICtrlCine{
  public:
    virtual void ingresarDireccion(string) = 0;
    virtual void ingresarCapacidad(int) = 0;
    virtual void AltaCine() = 0;
};

#endif

