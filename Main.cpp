#include "Socio.h"
#include "DtFecha.h"
#include "Mascota.h"
#include "Gato.h"
#include "Perro.h"

#include <iostream>
using namespace std;

int main(){
  DtFecha fecha1 = DtFecha(10,10,10);
  Socio s1 = Socio("12345", "Pepe", fecha1);

  Gato g1 = Gato("Gato1", Macho, 2.5, Largo);
  Gato g2 = Gato("Gato2", Hembra, 2.5, Corto);

  Perro p1 = Perro("Perro1", Macho, 6.0, Ovejero, false);
  cout << p1.getNombre() << endl;
  cout << p1.getVacunaCachorro() << endl;
  p1.setVacunaCachorro(true);
  cout << p1.getVacunaCachorro() << endl;

  return 0;
}
