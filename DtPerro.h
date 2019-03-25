#ifndef DTPERRO
#define DTPERRO

#include "RazaPerro.h"
#include "DtMascota.h"

class DtPerro : public DtMascota{
  private:
    RazaPerro raza;
    bool vacunaCachorro;
  public:
    DtPerro();
    DtPerro(string nombre, Genero genero, float peso, RazaPerro raza, bool vacunaCachorro);
    RazaPerro getRaza();
    bool getVacunaCachorro();
    ~DtPerro();
};

#endif
