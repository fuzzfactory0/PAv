
struct socios{
  Socio* socios[MAXSOCIOS];
  int tope = 0;
}coleccionSocios;

//Funcion auxiliar para agregarMascota
Socio* existeSocio(string ci){
  Socio* socEncontrado;
  bool encontre=false;
  int x=0;
  while(!encontre and x<=coleccionSocios.tope){
    if(strcmp(ci, coleccionSocios.socios[x]->getCi())=0){
      encontre=true;
      socEncontrado = coleccionSocios.socios[x];
    }
    x++;
  }
  if(encontre)
    return socEncontrado;
  else
    throw(invalid_argument)
}

void agregarMascota(string ci, DtMascota& dtMascota){
  int iter=0;
  try{
    Socio* s = existeSocio(ci);
    try{
      DtPerro& perro = dynamic_cast<DtPerro&>(dtMascota);
      Perro* dog = new Perro(perro.getNombre(), perro.getGenero(), perro.getPeso(), perro.getRaza(), perro.getVacunaCachorro());
      s.setMascota(dog);
    }catch(std::bad_cast){
      try{
        DtGato& gato = dynamic_cast<DtGato&>(dtMascota);
        Gato* cat = new Gato(gato.getNombre(), gato.getGenero(), gato.getPeso(), gato.getTipoPelo());
        s.setMascota(cat);
      }catch(std::bad_cast){
        cout << "Error\n";
      }
    }
  }catch(invalid_argument){
    cout << "Error al ingresar cedula" << endl;
  }
}
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
