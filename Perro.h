#ifndef PERRO
#define PERRO

#include "RazaPerro.h"
#include "Mascota.h"

class Perro : public Mascota{
  private:
    RazaPerro raza;
    bool vacunaCachorro;
  public:
    Perro();
    Perro(string nombre, Genero genero, float peso, RazaPerro raza, bool vacunaCachorro);
    RazaPerro getRaza();
    bool getVacunaCachorro();
    void setRaza(RazaPerro raza);
    void setVacunaCachorro(bool vacunaCachorro);
    ~Perro();
    float obtenerRacionDiaria();
};

#endif
