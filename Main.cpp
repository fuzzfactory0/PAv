#define MAX_MASCOTAS 10
#define MAX_SOCIOS 100

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

using namespace std;

struct socios{
  Socio* socios[MAX_SOCIOS];
  int tope = 0;
}coleccionSocios;

void registrarSocio(string ci, string nombre, DtMascota& dtMascota);
Socio* existeSocio(string ci);
void agregarMascota(string ci, DtMascota& dtMascota);
void ingresarConsulta(string motivo, string ci, DtFecha fecha);
void eliminarSocio(string ci);
DtMascota** obtenerMascotas(string ci, int& cantMascota);

int main(){
  int option;
  bool quit = false;
  while(!quit){
    cout << "\nBienvenido. Elija la opción";
    cout << "\n\t1) Registrar socio \n\t2) Ingresar una mascota \n\t3) Ingresar una consulta \n\t4) Ver Consultas Anteriores \n\t5) Eliminar Socio \n\t6) Obtener Mascota \n\t0) Salir\n\t";
    cin >> option;

    switch(option){
      case 1:{
        string name;
        string ci;
        string petname;
        int pettype;
        int gen;
        float petweight; 
        Genero petgender;

        cout << "\nIngrese el nombre del socio: "; cin >> name;
        cout << "\nIngrese la cedula del socio: "; cin >> ci;
        cout << "\nIngrese el tipo de mascota\n\t1) Gato\n\t2) Perro\n\t"; cin >> pettype;
        cout << "\nIngrese el nombre de la mascota: "; cin >> petname;
        cout << "\nIngrese el genero de la mascota\n\t1) Macho\n\t2) Hembra\n\t"; cin >> gen;
        switch(gen){
          case 1: petgender = Macho;  break;
          case 2: petgender = Hembra; break;
          default: throw invalid_argument("Entrada incorrecta");
        }
        cout << "\nIngrese el peso de la mascota: "; cin >> petweight;

        if(pettype == 1){
          int peloin;
          TipoPelo pelo;
          cout << "\nIngrese el tipo de pelo\n\t1) Corto\n\t2) Mediano\n\t3) Largo\n\t"; cin >> peloin;
          switch(peloin){
            case 1: pelo = Corto;   break;
            case 2: pelo = Mediano; break;
            case 3: pelo = Largo;   break;
          }
          DtGato g = DtGato(petname, petgender, petweight, pelo);
          registrarSocio(ci, name, g);
          cout << "\nSocio registrado.\n" << endl;
          cout << g;
        }
        else if (pettype == 2){
          int razain;
          RazaPerro raza;
          string vacuna;
          bool vaxx;
          cout << "\nIngrese la raza del perro\n\t1) Labrador\n\t2)Ovejero\n\t3)Bulldog\n\t4)Pitbull\n\t5)Collie\n\t6)Pekines\n\t6)Otro\n\t";
          cin >> razain;
          switch(razain){
            case 1: raza = Labrador;  break;
            case 2: raza = Ovejero;   break;
            case 3: raza = Bulldog;   break;
            case 4: raza = Pitbull;   break;
            case 5: raza = Collie;    break;
            case 6: raza = Pekines;   break;
            case 7: raza = Otro;      break;
          }
          cout << "\nSu perro fue vacunado?\n1) Si\n2) No\n\t"; cin >> vacuna;
          if(vacuna == 1) vaxx = true; else vaxx = false;
          DtPerro p = DtPerro(petname, petgender, petweight, raza, vaxx);
          registrarSocio(ci, name, p);
          cout << "\nSocio registrado.\n" << endl;
          cout << p;
        }
      }
      break;
      case 2:{
        string ci;
        int pettype;
        string petname;
        int gen;
        Genero petgender;
        float petweight;
        cout << "\nIngrese la cedula del socio: "; cin >> ci;
        cout << "\nIngrese el tipo de mascota\n\t1) Gato\n\t2) Perro\n\t"; cin >> pettype;
        cout << "\nIngrese el nombre de la mascota: "; cin >> petname;
        cout << "\nIngrese el genero de la mascota\n\t1) Macho\n\t2) Hembra\n\t"; cin >> gen;
        switch(gen){
          case 1: petgender = Macho;  break;
          case 2: petgender = Hembra; break;
          default: throw invalid_argument("Entrada incorrecta");
        }
        cout << "\nIngrese el peso de la mascota: "; cin >> petweight;

        if(pettype == 1){
          string peloin;
          TipoPelo pelo;
          cout << "\nIngrese el tipo de pelo\n\t1) Corto\n\t2) Mediano\n\t3) Largo\n\t"; cin >> peloin;
          switch(peloin){
            case 1: pelo = Corto;   break;
            case 2: pelo = Mediano; break;
            case 3: pelo = Largo;   break;
          }
          DtGato g = DtGato(petname, petgender, petweight, pelo);
          try{
            agregarMascota(ci, g);
            cout << "\nMascota agregada.\n" << endl;
            cout << g;
          }catch(invalid_argument){
            cout << "Error, no existe socio." << endl;
          }
        }
        else if(pettype == 2){
          int razain;
          RazaPerro raza;
          bool vaxx;
          string vacuna;
          cout << "\nIngrese la raza del perro\n\t1) Labrador\n\t2)Ovejero\n\t3)Bulldog\n\t4)Pitbull\n\t5)Collie\n\t6)Pekines\n\t6)Otro\n\t";
          cin >> razain;
          switch(razain){
            case 1: raza = Labrador;  break;
            case 2: raza = Ovejero;   break;
            case 3: raza = Bulldog;   break;
            case 4: raza = Pitbull;   break;
            case 5: raza = Collie;    break;
            case 6: raza = Pekines;   break;
            case 7: raza = Otro;      break;
          }
          cout << "\nSu perro fue vacunado?\n\t1) Si\n\t2) No\n\t"; cin >> vacuna;
          if(vacuna == 1) vaxx = true; else vaxx = false;
          DtPerro p = DtPerro(petname, petgender, petweight, raza, vaxx);
          try{
            agregarMascota(ci, p);
            cout << "\nMascota agregada.\n" << endl;
            cout << p;
          }catch(invalid_argument){
            cout << "\nError, no existe el socio\n" << endl;
          }
        }
      }
      break;
      case 3:{
        string id;
        string reason;
        int dia;
        int mes;
        int anio;
        cout << "\nIngrese la cedula del socio: "; cin >> id;
        cout << "\nIngrese el motivo de consulta: "; cin >> reason;
        cout << "\nIngrese el día: "; cin >> dia;
        cout << "\nIngrese el mes: "; cin >> mes;
        cout << "\nIngrese el año: "; cin >> anio;
        DtFecha fecha = DtFecha(dia, mes, anio);
        ingresarConsulta(reason, id, fecha);
      }
      break;
      case 4:{

      }
      break;
      case 5:{
        string ci;
        cout << "\nIngrese la cedula del socio: "; cin >> ci;
        eliminarSocio(ci);
        cout << "\nSocio Eliminado.\n" << endl;
      }
      break;
      case 6:{
          string ci;
          int cantMascota;
          DtMascota** arregloMascotas;
          cout << "\nIngrese la cedula del socio: "; cin >> ci;
          cout << "\nIngrese la cantidad de mascotas: "; cin >> cantMascota;
          arregloMascotas = obtenerMascotas(ci,cantMascota);
      }
      break;
      case 0: quit = true; break;
      default:
        cout << "\nLa opción ingresada no es correcta.\n" << endl;
    }
  }
  return 0;
}

void registrarSocio(string ci, string nombre, DtMascota& dtMascota){
  Socio* socio = new Socio(ci,nombre);
  if(coleccionSocios.tope < MAX_SOCIOS){
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
    coleccionSocios.tope++;
  }
}

Socio* existeSocio(string ci){
  Socio* socEncontrado;
  bool encontre=false;
  int x=0;
  while(!encontre and x<coleccionSocios.tope){
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
        cout << "\nError";
      }
    }
  }catch(invalid_argument){
    throw invalid_argument("\nNo existe socio");
  }
}

void ingresarConsulta(string motivo, string ci, DtFecha fecha){
  try{
    Socio* s = existeSocio(ci);
    Consulta* cons = new Consulta(fecha, motivo);
    s->setConsulta(cons);
    cout << "\nConsulta agregada.\n" << endl;
  }catch(invalid_argument){
    cout << "\nError, no existe socio" << endl;
  }
}

DtMascota** obtenerMascotas(string ci, int& cantMascota){
	Socio* s = existeSocio(ci);
  DtMascota** mascotas= new DtMascota*[cantMascota];
  int i = 0;
	while ( i < cantMascota && i<=s->getTopeMascota()){
    Perro* perro = dynamic_cast<Perro*>(s->getMascota(i));
    if (perro!=NULL){
      DtPerro* dog = new DtPerro(perro->getNombre(), perro->getGenero(), perro->getPeso(), perro->getRaza(), perro->getVacunaCachorro());
      mascotas[i]=dog;
    }
    Gato* gato = dynamic_cast<Gato*>(s->getMascota(i));
    if (gato!=NULL){
      DtGato* cat = new DtGato(gato->getNombre(), gato->getGenero(), gato->getPeso(), gato->getTipoPelo());
      mascotas[i]=cat;
    }
    i++;
}
	return mascotas;
}

void eliminarSocio(string ci){
  try{
    Socio* s = existeSocio(ci);
    int i = 0;
    while(ci.compare(coleccionSocios.socios[i]->getCi()) != 0)
      i++;
    if(i == coleccionSocios.tope){
      delete coleccionSocios.socios[i];
      coleccionSocios.tope--;
    }
    else{
      coleccionSocios.socios[i] = coleccionSocios.socios[coleccionSocios.tope];
      coleccionSocios.tope--;
    }
  }catch(invalid_argument){
    throw invalid_argument("\nNo existe socio");
  }
}
