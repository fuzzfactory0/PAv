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
#include <string>

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

Socio* existeSocio(string ci){
  Socio* socEncontrado;
  bool encontre=false;
  int x=0;
  while(!encontre and x<=coleccionSocios.tope){
    if(ci.compare(coleccionSocios.socios[x]->getCi())==0){
      encontre=true;
      socEncontrado = coleccionSocios.socios[x];
    }
    x++;
  }
  if(encontre){
    return socEncontrado;
  }
  else{
    throw invalid_argument("Error");
  }

}

void agregarMascota(string ci, DtMascota& dtMascota){
  int iter=0;
  try{
    Socio* s = existeSocio(ci);
    try{
      DtPerro& perro = dynamic_cast<DtPerro&>(dtMascota);
      Perro* dog = new Perro(perro.getNombre(), perro.getGenero(), perro.getPeso(), perro.getRaza(), perro.getVacunaCachorro());
      s->setMascota(dog);
    }catch(std::bad_cast){
      try{
        DtGato& gato = dynamic_cast<DtGato&>(dtMascota);
        Gato* cat = new Gato(gato.getNombre(), gato.getGenero(), gato.getPeso(), gato.getTipoPelo());
        s->setMascota(cat);
      }catch(std::bad_cast){
        cout << "Error\n";
      }
    }
  }catch(invalid_argument){
    cout << "Error, no existe socio" << endl;
  }
}


void ingresarConsulta(string motivo, string ci){
  try{
    Socio* s = existeSocio(ci);
    Consulta* cons = new Consulta(motivo);
    s->setConsulta(cons);

  }catch(invalid_argument){
    cout << "Error, no existe socio" << endl;
  }

}


int main(){
  DtFecha fecha1 = DtFecha(10,10,10);
  Socio s1 = Socio("12345", "Pepe", fecha1);

  DtGato g1 = DtGato("Gatete", Macho, 2.5, Largo);
  Gato g2 = Gato("Gato2", Hembra, 2.5, Corto);

  Perro p1 = Perro("Perro1", Macho, 6.0, Ovejero, false);
  cout << p1.getNombre() << endl;
  cout << p1.getVacunaCachorro() << endl;
  p1.setVacunaCachorro(true);
  cout << p1.getVacunaCachorro() << endl;


  DtPerro p12 = DtPerro("Firulais", Macho, 6.0, Ovejero, false);

  registrarSocio("5.043.098-8", "Jose", p12);

  agregarMascota("5.043.098-8", g1);

  cout << coleccionSocios.socios[0]->getNombre() << "\n";
  cout << coleccionSocios.socios[0]->getMascota(1) << "\n";

  ingresarConsulta("A mi perro le duele la muela, que hago?", "5.043.098-8" );

  cout << coleccionSocios.socios[0]->getConsulta(0) << "\n";



  return 0;
}
