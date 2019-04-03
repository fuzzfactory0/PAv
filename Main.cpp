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
#include "Consulta.h"
#include "Genero.h"
#include "RazaPerro.h"
#include "TipoPelo.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <typeinfo>
#include <stdlib.h>

using namespace std;

struct socios{
  Socio* socios[MAX_SOCIOS];
  int tope = 0;
}coleccionSocios;


void registrarSocio(string ci, string nombre, DtMascota& dtMascota);
Socio* existeSocio(string ci);
void agregarMascota(string ci, DtMascota& dtMascota);
void ingresarConsulta(string motivo, string ci, DtFecha fecha);
DtMascota** obtenerMascotas(string ci, int& cantMascota);
int obtenerPosicionSocio(string ci);
void eliminarSocio(string ci);
DtConsulta** verConsultasAntesDeFecha(DtFecha& fecha,string ciSocio, int& cantConsultas);

int main(){
  system("clear");
  int option;
  bool quit = false;
  string limpiarBuffer;

  while(!quit){
    cout << "\nBienvenido. Elija la opción:";
    cout << "\n\t1) Registrar socio \n\t2) Ingresar una mascota \n\t3) Ingresar una consulta \n\t4) Ver Consultas Anteriores \n\t5) Eliminar Socio \n\t6) Obtener Mascota \n\t0) Salir\n\tOpcion: ";
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

        cout << "\nIngrese el nombre del socio: "; getline(cin, limpiarBuffer,'\n'); getline(cin, name,'\n');
        cout << "Ingrese la cedula del socio: "; cin >> ci;
        cout << "Ingrese el tipo de mascota\n\t1) Gato\n\t2) Perro\n\tOpcion: "; cin >> pettype;
        while (pettype != 1 and pettype != 2) {
          cout << "\n - Error, seleccione opcion correcta - \n" << "\nIngrese nuevamente tipo de mascota: ";
          cin >> pettype;
        }
        cout << "Ingrese el nombre de la mascota: "; getline(cin, limpiarBuffer,'\n'); getline(cin, petname,'\n');
        cout << "Ingrese el genero de la mascota\n\t1) Macho\n\t2) Hembra\n\tOpcion: "; cin >> gen;
        cout << "Ingrese el peso de la mascota: "; cin >> petweight;
        switch(gen){
          case 1: petgender = Macho;  break;
          case 2: petgender = Hembra; break;
          default: throw invalid_argument("Entrada incorrecta");
        }
        if(pettype == 1){
          int peloin;
          TipoPelo pelo;
          cout << "Ingrese el tipo de pelo\n\t1) Corto\n\t2) Mediano\n\t3) Largo\n\tOpcion: "; cin >> peloin;
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
          int vacuna;
          bool vaxx;
          cout << "Ingrese la raza del perro\n\t1) Labrador\n\t2) Ovejero\n\t3) Bulldog\n\t4) Pitbull\n\t5) Collie\n\t6) Pekines\n\t7) Otro\n\tOpcion: ";
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
          cout << "Su perro fue vacunado?\n\t1) Si\n\t2) No\nOpcion: "; cin >> vacuna;
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
        cout << "\nIngrese el tipo de mascota\n\t1) Gato\n\t2) Perro\n\t Opcion: "; cin >> pettype;
        cout << "\nIngrese el nombre de la mascota: "; getline(cin, limpiarBuffer,'\n'); getline(cin, petname,'\n');
        cout << "\nIngrese el genero de la mascota\n\t1) Macho\n\t2) Hembra\n\t Opcion: "; cin >> gen;
        switch(gen){
          case 1: petgender = Macho;  break;
          case 2: petgender = Hembra; break;
          default: throw invalid_argument("Entrada incorrecta");
        }
        cout << "\nIngrese el peso de la mascota: "; cin >> petweight;
        if(pettype == 1){
          int peloin;
          TipoPelo pelo;
          cout << "\nIngrese el tipo de pelo\n\t1) Corto\n\t2) Mediano\n\t3) Largo\n\t Opcion: "; cin >> peloin;
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
          int vacuna;
          cout << "\nIngrese la raza del perro\n\t1) Labrador\n\t2) Ovejero\n\t3) Bulldog\n\t4) Pitbull\n\t5) Collie\n\t6) Pekines\n\t7) Otro\n\tOpcion: ";
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
          cout << "\nSu perro fue vacunado?\n\t1) Si\n\t2) No\n\tOpcion: "; cin >> vacuna;
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
        cout << "\nIngrese el motivo de consulta: "; getline(cin, limpiarBuffer,'\n'); getline(cin, reason,'\n');
        cout << "\nIngrese el día: "; cin >> dia;
        cout << "\nIngrese el mes: "; cin >> mes;
        cout << "\nIngrese el año: "; cin >> anio;
        DtFecha fecha = DtFecha(dia, mes, anio);
        ingresarConsulta(reason, id, fecha);
        /*
        id="123";
        reason="Consulta del 1/1/1111";
        dia=1;mes=1;anio=1111;
        DtFecha fecha = DtFecha(dia, mes, anio);
        ingresarConsulta(reason, id, fecha);

        id="123";
        reason="Consulta del 2/2/2222";
        dia=2;mes=2;anio=2222;
        DtFecha fecha2 = DtFecha(dia, mes, anio);
        ingresarConsulta(reason, id, fecha2);

        id="123";
        reason="Consulta del 3/3/3333";
        dia=3;mes=3;anio=3333;
        DtFecha fecha3 = DtFecha(dia, mes, anio);
        ingresarConsulta(reason, id, fecha3);

        id="123";
        reason="Consulta del 4/4/4444";
        dia=4;mes=4;anio=4444;
        DtFecha fecha4 = DtFecha(dia, mes, anio);
        ingresarConsulta(reason, id, fecha4);
        */
      }
      break;
      case 4:{
        string ciSocio;
        int dia;
        int mes;
        int anio;
        int cantConsultas;

        cout << "\nIngrese la cedula del socio: "; cin >> ciSocio;
        cout << "\nIngrese el día: "; cin >> dia;
        cout << "\nIngrese el mes: "; cin >> mes;
        cout << "\nIngrese el año: "; cin >> anio;
        DtFecha fecha = DtFecha(dia,mes,anio);
        cout << "\nIngrese la cantidad maxima de consultas que desea ver: " ; cin >> cantConsultas;

        DtConsulta** consultas = verConsultasAntesDeFecha(fecha,ciSocio,cantConsultas);
        int i = 0;
        if(consultas[0] == NULL) cout << "No hay consultas antes de la fecha indicada.\n";
        while(consultas[i] != NULL && i<cantConsultas){
            cout << *consultas[i];
            i++;
        }
      }
      break;
      case 5:{
        string ci;
        cout << "\nIngrese la cedula del socio: "; cin >> ci;
        eliminarSocio(ci);
      }
      break;
      case 6:{
        string ci;
        int cantMascota;
        DtMascota** arregloMascotas;
        cout << "\nIngrese la cedula del socio: "; cin >> ci;
        cout << "\nIngrese la cantidad de mascotas: "; cin >> cantMascota;
        cout << endl;
        arregloMascotas = obtenerMascotas(ci,cantMascota);
        for(int i = 0; i<cantMascota; i++){
          DtPerro* perro = dynamic_cast<DtPerro*>(arregloMascotas[i]);
            if (perro != NULL) {
              DtPerro dog = DtPerro(perro->getNombre(), perro->getGenero(), perro->getPeso(), perro->getRaza(), perro->getVacunaCachorro());
              cout << dog << endl;
            }
          DtGato* gato = dynamic_cast<DtGato*>(arregloMascotas[i]);
            if (gato != NULL) {
              DtGato cat = DtGato(gato->getNombre(), gato->getGenero(), gato->getPeso(), gato->getTipoPelo());
              cout << cat << endl;
            }
          }
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

int obtenerPosicionSocio(string ci){
  int i = 0;
  while(ci.compare(coleccionSocios.socios[i]->getCi()) != 0 && i <= coleccionSocios.tope)
    i++;
  if (i > coleccionSocios.tope)
    return -1;
  return i;
}

void eliminarSocio(string ci){
  try{
    Socio* s = existeSocio(ci);
    int i = obtenerPosicionSocio(ci);
    if(i == coleccionSocios.tope){
      delete coleccionSocios.socios[i];
      cout << "\nSocio Eliminado.\n" << endl;
    } else {
      delete coleccionSocios.socios[i];
      coleccionSocios.socios[i] = coleccionSocios.socios[coleccionSocios.tope];
      coleccionSocios.tope--;
      cout << "\nSocio Eliminado.\n" << endl;
    }
  }catch(invalid_argument){
    throw invalid_argument("No existe socio");
  }
}

DtMascota** obtenerMascotas(string ci, int& cantMascota) {
	Socio* s = existeSocio(ci);
	DtMascota** mascotas = new DtMascota*[cantMascota];
	int i = 0;
	while (i < cantMascota && i <= s->getTopeMascota()) {
		Perro* perro = dynamic_cast<Perro*>(s->getMascota(i));
		if (perro != NULL) {
			DtPerro* dog = new DtPerro(perro->getNombre(), perro->getGenero(), perro->getPeso(), perro->getRaza(), perro->getVacunaCachorro());
			mascotas[i] = dog;
		}
		Gato* gato = dynamic_cast<Gato*>(s->getMascota(i));
		if (gato != NULL) {
			DtGato* cat = new DtGato(gato->getNombre(), gato->getGenero(), gato->getPeso(), gato->getTipoPelo());
			mascotas[i] = cat;
		}
		i++;
	}
	return mascotas;
}

DtConsulta** verConsultasAntesDeFecha(DtFecha& fecha,string ciSocio, int& cantConsultas) {
	/*devuelve   las  consultas antes de cierta fecha.*/
	Socio* s = existeSocio(ciSocio);
	DtConsulta** consultas= new DtConsulta*[cantConsultas];
	int i=0;
	int tope=0;
	while (tope < cantConsultas && i < s->getTopeConsulta()){
		DtFecha fechaConsulta= s->getConsulta(i)->getFechaConsulta();
		if (fechaConsulta<fecha){
			consultas[tope]= new DtConsulta(s->getConsulta(i)->getFechaConsulta(),s->getConsulta(i)->getMotivo());
			tope++;
		}
		i++;
	}
  consultas[tope]=NULL;
	return consultas;

}
