#ifndef SOCIO
#define SOCIO
#include "Mascota.h"
#include "DtFecha.h"
#include "Consulta.h"

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
  string getCi();
  void setCi(string);
  string getNombre();
  void setNombre(string);
  DtFecha getFechaIngreso();
  void setFechaIngreso(DtFecha);
  int getTopeConsulta();
  void setTopeconsulta();
  int getTopeMascota();
  void setTopeMascota();
  ~Socio();
  //void agregarConsulta(DtConsulta);
  void setMascota(DtMascota);
};

#endif
