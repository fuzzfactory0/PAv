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
  if(coleccionSocios.tope < MAX_SOCIOS)
    coleccionSocios.socios[coleccionSocios.tope] = socio;
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
  if(encontre)
    return socEncontrado;
  else
    throw invalid_argument("Error");
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
  int option;
  bool quit = false;
  while(!quit){
    cout << "Ingrese 1 para registrar socio, \n2 para ingresar una mascota, \n3 para ingresar una consulta.\n" << endl;
    cin >> option;

    switch(option){
      case 1:{
        string name;
        string ci;
        int pettype;
        string petname;
        string gen;
        Genero petgender;
        float petweight;
        cout << "Ingrese el nombre del socio:\n" << endl;
        cin >> name;
        cout << "Ingrese la cedula del socio:\n" << endl;
        cin >> ci;
        cout << "Ingrese el tipo de mascota (1 para gato, 2 para perro):\n" << endl;
        cin >> pettype;
        cout << "Ingrese el nombre de la mascota:\n" << endl;
        cin >> petname;
        cout << "Ingrese el genero de la mascota (Macho o Hembra):\n" << endl;
        cin >> gen;
        if(gen == "Macho") petgender = Macho;
        else if(gen == "Hembra") petgender = Hembra;
        cout << "Ingrese el peso de la mascota:\n" << endl;
        cin >> petweight;

        if(pettype == 1){
          string peloin;
          TipoPelo pelo;
          cout << "Ingrese el tipo de pelo (Corto, Mediano o Largo):\n" << endl;
          cin >> peloin;
          if(peloin == "Corto") pelo = Corto;
          else if (peloin == "Mediano") pelo = Mediano;
          else if (peloin == "Largo") pelo = Largo;
          DtGato g = DtGato(petname, petgender, petweight, pelo);
          registrarSocio(ci, name, g);
          cout << "Socio registrado.\n" << endl;
        }
        else{
          string razain;
          RazaPerro raza;
          bool vaxx;
          cout << "Ingrese la raza del perro:\n" << endl;
          cin >> razain;
          if(razain == "Labrador") raza = Labrador;
          else if (razain == "Ovejero") raza = Ovejero;
          else if (razain == "Bulldog") raza = Bulldog;
          else if (razain == "Pitbull") raza = Pitbull;
          else if (razain == "Collie") raza = Collie;
          else if (razain == "Pekines") raza = Pekines;
          else if (razain == "Otro") raza = Otro;
          cout << "Su perro fue vacunado? (Ingrese 1 para Si, 0 para No)}\n" << endl;
          cin >> vaxx;
          DtPerro p = DtPerro(petname, petgender, petweight, raza, vaxx);
          registrarSocio(ci, name, p);
          cout << "Socio registrado.\n" << endl;
        }
      }
      break;
      case 2:{
        string ci;
        int pettype;
        string petname;
        string gen;
        Genero petgender;
        float petweight;
        cout << "Ingrese la cedula del socio:\n" << endl;
        cin >> ci;
        cout << "Ingrese el tipo de mascota (1 para gato, 2 para perro):\n" << endl;
        cin >> pettype;
        cout << "Ingrese el nombre de la mascota:\n" << endl;
        cin >> petname;
        cout << "Ingrese el genero de la mascota (Macho o Hembra):\n" << endl;
        cin >> gen;
        if(gen == "Macho") petgender = Macho;
        else if(gen == "Hembra") petgender = Hembra;
        cout << "Ingrese el peso de la mascota:\n" << endl;
        cin >> petweight;

        if(pettype == 1){
          string peloin;
          TipoPelo pelo;
          cout << "Ingrese el tipo de pelo (Corto, Mediano o Largo):\n" << endl;
          cin >> peloin;
          if(peloin == "Corto") pelo = Corto;
          else if (peloin == "Mediano") pelo = Mediano;
          else if (peloin == "Largo") pelo = Largo;
          DtGato g = DtGato(petname, petgender, petweight, pelo);
          agregarMascota(ci, g);
        }
        else{
          string razain;
          RazaPerro raza;
          bool vaxx;
          cout << "Ingrese la raza del perro:\n" << endl;
          cin >> razain;
          if(razain == "Labrador") raza = Labrador;
          else if (razain == "Ovejero") raza = Ovejero;
          else if (razain == "Bulldog") raza = Bulldog;
          else if (razain == "Pitbull") raza = Pitbull;
          else if (razain == "Collie") raza = Collie;
          else if (razain == "Pekines") raza = Pekines;
          else if (razain == "Otro") raza = Otro;
          cout << "Su perro fue vacunado? (Ingrese 1 para Si, 0 para No)\n" << endl;
          cin >> vaxx;
          DtPerro p = DtPerro(petname, petgender, petweight, raza, vaxx);
          agregarMascota(ci, p);
          cout << "Mascota agregada.\n" << endl;
        }
      }
      break;
      case 3:{
        string id;
        string reason;
        cout << "Ingrese la cedula del socio:\n" << endl;
        cin >> id;
        cout << "Ingrese el motivo de consulta:\n" << endl;
        cin >> reason;
        ingresarConsulta(reason, id);
        cout << "Consulta agregada.\n" << endl;
      }
      break;
      case 4: quit = true; break;
      default:
        cout << "La opción ingresada no es correcta.\n" << endl;
    }
  }
  return 0;
}
