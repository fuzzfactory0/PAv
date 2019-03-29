#ifndef SOCIO
#define SOCIO
#include "Mascota.h"
#include "DtFecha.h"
#include "Consulta.h"
#include "Perro.h"
#include "Gato.h"


#include <iostream>

using namespace std;

class Socio{
private:
  string ci;
  string nombre;
  DtFecha fechaIngreso;
  Consulta* consultas[20];
  int topeConsulta=0;
  Mascota* mascotas[10];
  int topeMascota=0;
public:
  Socio();
  Socio(string ci, string nom, DtFecha fi);
  Socio(string ci, string nom); //PRUEBAS
  string getCi();
  void setCi(string);
  string getNombre();
  void setNombre(string);
  DtFecha getFechaIngreso();
  void setFechaIngreso(DtFecha);
  void setMascota(Mascota* m);
  int getTopeConsulta();
  void setTopeconsulta();
  int getTopeMascota();
  ~Socio();
  void setConsulta(Consulta* consulta);
  Mascota* getMascota(int i); //SOLO para prueba y debug, no es una funcion definitiva
  string getConsulta(int i);//SOLO para prueba y debug, no es una funcion definitiva
};

#endif
