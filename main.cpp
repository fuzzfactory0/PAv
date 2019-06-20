#include "Interfaz/ICtrlUsuario.h"
#include "Fabrica.h"
#include "DT/Direccion.h"
#include "DT/DtCine.h"
#include "DT/DtFuncion.h"
#include "DT/DtSala.h"
#include "DT/TipoPago.h"
#include <iostream>
#include <list>
#include <string>
#include "colormod.h"

using namespace std;

void menu();
void iniciarSesion();
void altaCine();
void altaFuncion();
void crearReserva();
void puntuarPelicula();
void comentarPelicula();
void eliminarPelicula();
void verInfoPelicula();
void verComentariosPelicula();

int main(){
  //creación de fabrica e icontroladores
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlUsuario* iuser = fab->getICtrlUsuario();
  ICtrlPelicula* ipeli = fab->getICtrlPelicula();
  //Cargar usuarios al sistema
  iuser->cargarUsuarios();
  ipeli->cargarPeliculas();

  int opcion;
  while(1){
    menu();
    cin >> opcion;
    switch(opcion){
      case 1:
        iniciarSesion();
        break;
      case 2:
        altaCine();
        break;
      case 3:
        altaFuncion();
        break;
      case 4:
        crearReserva();
        break;
      case 5:
        puntuarPelicula();
        break;
      case 6:
        comentarPelicula();
        break;
      case 7:
        eliminarPelicula();
        break;
      case 8:
        verInfoPelicula();
        break;
      case 9:
        verComentariosPelicula();
        break;
      case 0:
        system("make clean"); //!Por conveniencia
        system("clear");
        exit(0);
        break;
      default:
        cout << "La opción ingresada no es correcta";
    }
  }
}

void menu(){
  string user;
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlUsuario* iuser = fab->getICtrlUsuario();
  if (iuser->checkSesion()){
    user = iuser->getUsuarioSesion();
  }
  else user = "ANONIMO.";
  system("clear");
  Color::Modifier r(Color::FG_RED);
  Color::Modifier b(Color::FG_BLUE);
  Color::Modifier y(Color::FG_YELLOW);
  Color::Modifier d(Color::FG_DEFAULT);
  Color::Modifier g(Color::FG_LIGHT_GREEN);

  if (iuser->checkSesionAdmin()) Color::Modifier x(Color::FG_DEFAULT);
  else Color::Modifier x(FG_RED);

  cout <<b<<"    ╔═════════════════════════════════════════════════════╗"<<endl;
  cout <<"    ║"<<y<<"    ▂▂▃▃▅▅▇▇██▓▓▒▒░░  MENU CINE  ░░▒▒▓▓██▇▇▅▅▃▃▂▂    "<<b<<"║    "<<endl;
  if (iuser->checkSesion()){
  cout <<"╔═══╩═════════════════════════════════════════════════════╩═══╗"<<endl;
  cout <<"║"<<d<<"      Sesion inciada como:    "<<b<<" "<<d<<"\t"<<user<<" "<<"\t      "<<b<<"║"<<endl;
  cout <<"╠══════════════════════════════╦══════════════════════════════╣"<<endl;}
  else cout <<"╔═══╩══════════════════════════╦══════════════════════════╩═══╗"<<endl;
  cout <<"║"<<d<<"       1. Iniciar Sesión      "<<b<<"║"<<x<<"         2. Alta Cine         "<<b<<"║"<<endl;
  cout <<"╠══════════════════════════════╬══════════════════════════════╣"<<endl;
  cout <<"║"<<x<<"        3. Alta Función       "<<b<<"║"<<d<<"        4. Crear Reserva      "<<b<<"║"<<endl;
  cout <<"╠══════════════════════════════╬══════════════════════════════╣"<<endl;
  cout <<"║"<<d<<"       5. Puntuar Película    "<<b<<"║"<<d<<"     6. Comentar Película     "<<b<<"║"<<endl;
  cout <<"╠══════════════════════════════╬══════════════════════════════╣"<<endl;
  cout <<"║"<<x<<"      7. Eliminar Película    "<<b<<"║"<<d<<"    8. Ver Info de Película   "<<b<<"║"<<endl;
  cout <<"╠══════════════════════════════╩══════════════════════════════╣"<<endl;
  cout <<"║"<<d<<"           9. Ver Comentarios y Puntajes de Película         "<<b<<"║"<<endl;
  cout <<"╠═════════════════════════════════════════════════════════════╣"<<endl;
  cout <<"║"<<y<<"█▄█▀█▄█▀█▄█▀█▄█▀█▄█▀█▄    0. Salir     ▄█▀█▄█▀█▄█▀█▄█▀█▄█▀█▄█"<<b<<"║"<<endl;
  cout <<"╚═════════════════════════════════════════════════════════════╝"<<d<<endl;
  cout <<"Seleccione una opcion: "<<g;
}
//USAR CIN.IGNORE???
//USAR CIN.IGNORE???
//USAR CIN.IGNORE???
//USAR CIN.IGNORE???
//USAR CIN.IGNORE??? <- no le den bola, nota personal xD

void iniciarSesion(){
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlUsuario* iuser = fab->getICtrlUsuario();

  string nickname, password, buff;
  bool confirmacion = true;

  iuser = fab->getICtrlUsuario();
  cout << "nickname: ";
  cin >> nickname;
  iuser->ingresarNickname(nickname);
  cout << "password: ";
  cin >> password;
  if(iuser->verificarPassword(password)){
    if (iuser->checkSesion()){
      cout << "Esto cerrará la sesión del usuario " << iuser->getUsuarioSesion() << " e iniciará una sesión para el usuario " << nickname << ". ¿Continuar?\n 1: Si 0: No ";
      cin >> confirmacion;
    }
    if (confirmacion){
      iuser->iniciarSesion();
      cout << "Sesión iniciada correctamente para el usuario " << nickname << "\nIngrese cualquier caracter para continuar..." << endl;
      cin >> buff;
    }
  }
  else{
    cout << "El nombre de usuario o la contraseña son incorrectos." << "\nIngrese cualquier caracter para continuar..."<< endl;
    cin >> buff;
  }
}

void altaCine(){
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlCine* icine = fab->getICtrlCine();
  ICtrlUsuario* iuser = fab->getICtrlUsuario();

  if (!iuser->checkSesion()){
    cout << "Debe iniciar sesión primero." << endl;
    return;
  }
  else if (!iuser->checkSesionAdmin()){
    cout << "Debe ser administrador para poder realizar esta operación." << endl;
    return;
  }
  else{
    string buff, calle;
    int numero;
    bool confirmacion;
    cout << "Ingrese la calle: ";
    cin >> calle;
    cout << "Ingrese el número: ";
    cin >> numero;
    Direccion dir = Direccion(calle, numero);
    icine->ingresarDireccion(dir);
    cout << "Para ingresar salas, ingrese la capacidad de una sala y presione enter.\nSi quiere dejar de ingresar salas, ingrese 0."<<endl;
    int capac = 1;
    while (capac != 0){
      cout << "Ingrese una capacidad: ";
      cin >> capac;
      icine->ingresarCapacidad(capac);
      if (capac!=0) cout << "Sala registrada." << endl;
    }
    cout << "¿Desea confirmar el alta del cine? 1: Si, 0: No"<<endl;
    cin >> confirmacion;
    if (confirmacion){
      icine->altaCine();
      delete icine;
      cout << "Cine dado de alta. Ingrese cualquier caracter para continuar..."<<endl;
      cin >> buff;
      return;
    }
    else{
      delete icine;
      cout << "Se ha cancelado el alta del cine. Ingrese cualquier caracter para continuar..."<<endl;
      cin >> buff;
      return;
    }
  }
}

void altaFuncion(){
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlCine* icine = fab->getICtrlCine();
  ICtrlUsuario* iuser = fab->getICtrlUsuario();
  if (!iuser->checkSesion()){
    cout << "Debe iniciar sesión primero." << endl;
    return;
  }
  else if (!iuser->checkSesionAdmin()){
    cout << "Debe ser administrador para poder realizar esta operación." << endl;
    return;
  }
  else{
    int cineid, funcid, dia, mes, anio;
    string pelicula, horainicio, horafin, buff;
    bool confirmacion;

    list<string> titulos = icine->listarTitulosPeliculas();
    cout << "-Listado de películas del sistema-";
    for(list<string>::iterator it = titulos.begin(); it!=titulos.end(); ++it){
      cout << (*it) << endl;
    }
    cout << endl;
    cout << "Seleccione la película para la que desea crear una función: ";
    cin >> pelicula;

    list<DtCine> cines = icine->listarIdCines();
    for(list<DtCine>::iterator it = cines.begin(); it != cines.end(); ++it){
      cout << (*it) << endl;
    }
    cout << "Ingrese la ID del cine deseado: ";
    cin >> cineid;
    list<DtSala> salas = icine->seleccionarCineFuncion(cineid);
    for(list<DtSala>::iterator it = salas.begin(); it!=salas.end(); ++it){
      cout << (*it) << endl;
    }
    cout << "Seleccione la función deseada" << endl;
    cin >> funcid;
    icine->seleccionarSalaFuncion(funcid);
    cout << "Ingrese la hora de inicio de la función.\n(Formato requerido: Horas:Minutos): ";
    cin >> horainicio;
    cout << "Ingrese la hora de fin de la función.\n(Formato requerido: Horas:Minutos): ";
    cin >> horafin;
    cout << "Ingrese el año de la función: ";
    cin >> anio;
    cout << "Ingrese el mes de la función: ";
    cin >> mes;
    cout << "Ingrese el día de la función: ";
    cin >> dia;
    Horario hora = Horario(horainicio, horafin);
    Fecha fecha = Fecha(dia, mes, anio);
    icine->ingresarHorario(fecha, hora);

    cout << "¿Desea confirmar el alta de la función? 1: Si, 0: No"<<endl;
    cin >> confirmacion;
    if (confirmacion){
      icine->altaFuncion();
      delete icine;
      cout << "Función dada de alta. Ingrese cualquier caracter para continuar..."<<endl;
      cin >> buff;
    }
    else{
      delete icine;
      cout << "Se ha cancelado el alta de la función. Ingrese cualquier caracter para continuar..."<<endl;
      cin >> buff;
    }
  }
}

void crearReserva(){
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlCine* icine = fab->getICtrlCine();
  ICtrlUsuario* iuser = fab->getICtrlUsuario();
  if (!iuser->checkSesion()){
    cout << "Debe iniciar sesión primero." << endl;
    return;
  }
  else{
    string pelicula, buff, entepago;
    int cineid, funcid, cantAsientos;
    TipoPago modopago;
    bool verprecio, confirmacion;

    list<string> titulos = icine->listarTitulosPeliculas();
    cout << "-Listado de películas del sistema-";
    for(list<string>::iterator it = titulos.begin(); it!=titulos.end(); ++it){
      cout << (*it) << endl;
    }
    cout << endl;
    cout << "Seleccione la película para la que desea crear una reserva: ";
    cin >> pelicula;
    list<DtCine> cines = icine->listarCines();
    cout << "La película se proyecta en los siguientes cines:" << endl;
    for(list<DtCine>::iterator it=cines.begin(); it!=cines.end(); ++it){
      cout << "\t" << (*it) << endl;
    }
    cout << "Seleccione el cine en el que desea crear la reserva: ";
    cin >> cineid;
    list<DtFuncion> funciones = icine->seleccionarCineReserva(cineid);
    for(list<DtFuncion>::iterator it=cines.begin(); it!=cines.end(); ++it){
      cout << "\t" << (*it) << endl;
    }
    cout << "Seleccione la función deseada: ";
    cin >> funcid;
    icine->seleccionarFuncion(funcid);

    cout << "Ingrese la cantidad de entradas que desea reservar: ";
    cin >> cantAsientos;
    icine->ingresarCantidadAsientos(cantAsientos);

    cout << "¿Qué metodo de pago desea utilizar? (1: Debito 2: Credito) ";
    cin >> modopago;
    icine->ingresarModoPago(modopago);

    if (modopago == Deb){
      cout << "Ingrese el nombre del banco de su tarjeta: ";
      cin >> entepago;
      icine->ingresarNombreBanco(entepago);
    }
    else if (modopago == Cred){
      cout << "Ingrese la financiera de su tarjeta: ";
      cin >> entepago;
      icine->ingresarFinanciera(entepago);
    }

    cout << "¿Desea ver el precio total de su reserva antes de confirmarla? 1: Si 0: No ";
    cin >> verprecio;
    if (verprecio) cout << "El precio total de su reserva es de $" << icine->verPrecioTotal() << endl;

    cout << "¿Desea confirmar su reserva? 1: Si, 0: No"<<endl;
    cin >> confirmacion;
    if (confirmacion){
      icine->confirmarReserva();
      delete icine;
      cout << "Reserva realizada. Ingrese cualquier caracter para continuar..."<<endl;
      cin >> buff;
    }
    else{
      delete icine;
      cout << "Se ha cancelado la reserva. Ingrese cualquier caracter para continuar..."<<endl;
      cin >> buff;
    }
  }
}

void puntuarPelicula(){
  float puntaje = 0;
  int opc;
  string tituloPel;
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlResenia* irese = fab->getICtrlResenia();
  if (!iuser->checkSesion()){
    cout << "Debe iniciar sesión primero." << endl;
    return;
  }
  list<string> peliculas = irese->listarTitulosPeliculas();
  cout << "-Listado de películas del sistema-";
  for(list<string>::iterator it = peliculas.begin(); it!=peliculas.end(); ++it){
    cout << (*it)->getTitulo() << endl;
  }
  cout << endl;
  cout << "\nSeleccione la pelicula que desea puntuar: ";
  getline(cin >> ws, tituloPel);
  irese->seleccionarPelicula(tituloPel);
  cout << "1. Ver el puntaje" << endl;
  cout << "2. Ingresar puntaje" <<endl;
  cout << "Opcion: ";
  cin >> opc;
  switch(opc){
    case 1:
        puntaje = irese->verPuntaje();
        if (puntaje == 0){
          cout << "Aún no has puntuado la pelicula  " << tituloPel <<". ¿Qué estás esperando?";
        }
        else{
          cout <<"Tu puntaje para la pelicula " <<tituloPel << "es: " <<puntaje;
        }
      break;
    case 2:
        cout <<"Ingresa el puntaje para la pelicula "<<tituloPel << ": ";
        cin >> puntaje;
        irese->ingresarPuntaje(puntaje);
      break;
    default:
      cout << "La opción ingresada no es correcta";
}
  break;

}

void comentarPelicula(){}

void eliminarPelicula(){}

void verInfoPelicula(){}

void verComentariosPelicula(){}
