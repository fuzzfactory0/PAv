#include "Socio.h"
#include "Mascota.h"
#include "Gato.h"
#include "Perro.h"
#include "DtFecha.h"
#include "DtMascota.h"
#include "DtPerro.h"
#include "DtGato.h"
#include "DtConsulta.h"
#include <iostream>
#define MAX_MASCOTAS 10
#define MAX_SOCIOS 100

using namespace std;

struct socios{
  Socio* socios[MAX_SOCIOS];
  int tope = 0;
}coleccionSocios;


void registrarSocio(string ci, string nombre, DtMascota& dtMascota){

  Socio* socio = new Socio(ci,nombre);
  if(coleccionSocios.tope < MAX_SOCIOS){
    coleccionSocios.socios[coleccionSocios.tope] = socio;
  }
  try{
    DtPerro& perro = dynamic_cast<DtPerro&>(dtMascota);
    Perro* dog = new Perro(perro.getNombre(), perro.getGenero(), perro.getPeso(), perro.getRaza(), perro.getVacunaCachorro());
    dog->setRacionDiaria(0);
    coleccionSocios.socios[coleccionSocios.tope]->setMascota(dog);
  }catch(std::bad_cast){
    DtGato& gato = dynamic_cast<DtGato&>(dtMascota);
    Gato* cat = new Gato(gato.getNombre(), gato.getGenero(), gato.getPeso(), gato.getTipoPelo());
    cat->setRacionDiaria(0);
    coleccionSocios.socios[coleccionSocios.tope]->setMascota(cat);
  }
}

int main(){
  DtFecha fecha1 = DtFecha(10,10,10);
  Socio s1 = Socio("12345", "Pepe", fecha1);

  DtGato g1 = DtGato("Misifu", Macho, 2.5, Largo);
  DtGato g2 = DtGato("Callejera", Hembra, 2.5, Corto);

  DtPerro p1 = DtPerro("Firulais", Macho, 6.0, Ovejero, false);

  registrarSocio("5.043.098-8", "Jose", p1);

  cout << coleccionSocios.socios[0]->getNombre() << "\n";
  cout << coleccionSocios.socios[0]->getMascota(0) << "\n";

  return 0;
}
