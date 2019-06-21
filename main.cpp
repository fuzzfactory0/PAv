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
#include <limits>
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
int comprobarSesion();

int main(){
  //creación de fabrica e icontroladores
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlUsuario* iuser = fab->getICtrlUsuario();
  ICtrlPelicula* ipeli = fab->getICtrlPelicula();
  //Cargar usuarios al sistema
  iuser->cargarUsuarios();
  cout << "Usuarios cargados"<<endl;
  ipeli->cargarPeliculas();
  cout << "Peliculas cargadas"<<endl;

  int opcion;
  while(1){
    menu();
    while (!(cin >> opcion)){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Por favor ingrese una opción válida: ";
    }
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
        //system("make clean"); //!Por conveniencia
        //system("clear");
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
  //system("clear");
  Color::Modifier r(Color::FG_RED);
  Color::Modifier b(Color::FG_BLUE);
  Color::Modifier y(Color::FG_YELLOW);
  Color::Modifier d(Color::FG_DEFAULT);
  Color::Modifier g(Color::FG_LIGHT_GREEN);
  bool admin = iuser->checkSesionAdmin();
  
  cout <<b<<"    ╔═════════════════════════════════════════════════════╗"<<endl;
  cout <<"    ║"<<y<<"    ▂▂▃▃▅▅▇▇██▓▓▒▒░░  MENU CINE  ░░▒▒▓▓██▇▇▅▅▃▃▂▂    "<<b<<"║    "<<endl;
  if (iuser->checkSesion()){
  cout <<"╔═══╩═════════════════════════════════════════════════════╩═══╗"<<endl;
  cout <<"║"<<d<<"      Sesion inciada como:    "<<b<<" "<<d<<"\t"<<user<<" "<<"\t      "<<b<<"║"<<endl;
  cout <<"╠══════════════════════════════╦══════════════════════════════╣"<<endl;}
  else cout <<"╔═══╩══════════════════════════╦══════════════════════════╩═══╗"<<endl;
  if (admin){
  cout <<"║"<<d<<"       1. Iniciar Sesión      "<<b<<"║"<<d<<"         2. Alta Cine         "<<b<<"║"<<endl;}
  else{
  cout <<"║"<<d<<"       1. Iniciar Sesión      "<<b<<"║"<<r<<"         2. Alta Cine         "<<b<<"║"<<endl;}
  cout <<"╠══════════════════════════════╬══════════════════════════════╣"<<endl;
  if (admin){
  cout <<"║"<<d<<"        3. Alta Función       "<<b<<"║"<<d<<"        4. Crear Reserva      "<<b<<"║"<<endl;}
  else{
  cout <<"║"<<r<<"        3. Alta Función       "<<b<<"║"<<d<<"        4. Crear Reserva      "<<b<<"║"<<endl;}
  cout <<"╠══════════════════════════════╬══════════════════════════════╣"<<endl;
  cout <<"║"<<d<<"       5. Puntuar Película    "<<b<<"║"<<d<<"     6. Comentar Película     "<<b<<"║"<<endl;
  cout <<"╠══════════════════════════════╬══════════════════════════════╣"<<endl;
  if (admin){
  cout <<"║"<<d<<"      7. Eliminar Película    "<<b<<"║"<<d<<"    8. Ver Info de Película   "<<b<<"║"<<endl;}
  else{
  cout <<"║"<<r<<"      7. Eliminar Película    "<<b<<"║"<<d<<"    8. Ver Info de Película   "<<b<<"║"<<endl;}
  cout <<"╠══════════════════════════════╩══════════════════════════════╣"<<endl;
  cout <<"║"<<d<<"           9. Ver Comentarios y Puntajes de Película         "<<b<<"║"<<endl;
  cout <<"╠═════════════════════════════════════════════════════════════╣"<<endl;
  cout <<"║"<<y<<"█▄█▀█▄█▀█▄█▀█▄█▀█▄█▀█▄    0. Salir     ▄█▀█▄█▀█▄█▀█▄█▀█▄█▀█▄█"<<b<<"║"<<endl;
  cout <<"╚═════════════════════════════════════════════════════════════╝"<<d<<endl;
  cout <<"Seleccione una opcion: ";
}

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
      cout << "Esto cerrará la sesión del usuario " << iuser->getUsuarioSesion() << " e iniciará una\nsesión para el usuario " << nickname << ". ¿Continuar?\n 1: Si 0: No ";
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

  string buff;
  if (comprobarSesion() < 1){
    cout << "Debe iniciar sesión primero.\nIngrese cualquier caracter para continuar..." << endl;
    cin >> buff;
    return;
  }
  else if (comprobarSesion() < 2){
    cout << "Debe ser administrador para poder realizar esta operación.\nIngrese cualquier caracter para continuar..." << endl;
    cin >> buff;
    return;
  }
  else{
    string calle;
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
    cout << "¿Desea confirmar el alta del cine? 1: Si, 0: No";
    cin >> confirmacion;
    if (confirmacion){
      icine->altaCine();
      delete icine;
      cout << "Cine dado de alta.\nIngrese cualquier caracter para continuar..."<<endl;
      cin >> buff;
      return;
    }
    else{
      delete icine;
      cout << "Se ha cancelado el alta del cine.\nIngrese cualquier caracter para continuar..."<<endl;
      cin >> buff;
      return;
    }
  }
}

void altaFuncion(){
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlCine* icine = fab->getICtrlCine();
  string buff;
  if (comprobarSesion() < 1){
    cout << "Debe iniciar sesión primero.\nIngrese cualquier caracter para continuar..." << endl;
    cin >> buff;
    return;
  }
  else if (comprobarSesion() < 2){
    cout << "Debe ser administrador para poder realizar esta operación.\nIngrese cualquier caracter para continuar..." << endl;
    cin >> buff;
    return;
  }
  else{
    int cineid, funcid, dia, mes, anio;
    string pelicula, horainicio, horafin;
    bool confirmacion;

    list<string> titulos = icine->listarTitulosPeliculas();
    cout << "-Listado de películas del sistema-" << endl;
    for(list<string>::iterator it = titulos.begin(); it!=titulos.end(); ++it){
      cout << (*it) << endl;
    }
    cout << endl;
    cout << "Seleccione la película para la que desea crear una función: ";
    getline(cin >> ws, pelicula);
    try{
      icine->seleccionarPelicula(pelicula);
    }catch(int exc){
      if (exc == 404){
        cout<<"La película " << pelicula << " no existe." << endl; 
        cout<<"Ingrese cualquier caracter para continuar...";
        cin>>buff;
        return;
      } 
    }
    cout << "\n-Listado de cines del sistema-" << endl;
    list<DtCine> cines = icine->listarIdCines();
    for(list<DtCine>::iterator it = cines.begin(); it != cines.end(); ++it){
      cout << (*it) << endl;
    }
    cout << "\nIngrese la ID del cine deseado: ";
    cin >> cineid;
    bool existe = false;
    for(list<DtCine>::iterator it = cines.begin(); it != cines.end(); ++it){
      existe = (existe || (*it).getId() == cineid);
    }
    if (!existe){
      cout << "El cine seleccionado no existe en el sistema.\nIngrese cualquier caracter para continuar..." <<endl;
      cin >> buff;
      delete icine;
      return;
    }
    cout << "\n-Listado de salas del cine seleccionado-" << endl;
    list<DtSala> salas = icine->seleccionarCineFuncion(cineid);
    for(list<DtSala>::iterator it = salas.begin(); it!=salas.end(); ++it){
      cout << (*it) << endl;
    }
    cout << "\nSeleccione la ID de la sala deseada: ";
    cin >> funcid;
    existe = false;
    for(list<DtSala>::iterator it = salas.begin(); it != salas.end(); ++it){
      existe = (existe || (*it).getId() == funcid);
    }
    if (!existe){
      cout << "La sala seleccionada no existe en el cine.\nIngrese cualquier caracter para continuar..." <<endl;
      cin >> buff;
      delete icine;
      return;
    }
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

    cout << "¿Desea confirmar el alta de la función? 1: Si, 0: No: ";
    cin >> confirmacion;
    if (confirmacion){
      icine->altaFuncion();
      delete icine;
      cout << "Función dada de alta.\nIngrese cualquier caracter para continuar...";
      cin >> buff;
    }
    else{
      delete icine;
      cout << "Se ha cancelado el alta de la función.\nIngrese cualquier caracter para continuar...";
      cin >> buff;
    }
  }
}

void crearReserva(){
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlCine* icine = fab->getICtrlCine();
  string buff;

  if (comprobarSesion() < 1){
    cout << "Debe iniciar sesión primero.\nIngrese cualquier caracter para continuar..." << endl;
    cin >> buff;
    return;
  }
  else{
    string pelicula, entepago;
    int cineid, funcid, cantAsientos, pago;
    TipoPago modopago;
    bool verprecio, confirmacion;
    DtPelicula infopeli;

    list<string> titulos = icine->listarTitulosPeliculas();
    cout << "-Listado de películas del sistema-" << endl;
    for(list<string>::iterator it = titulos.begin(); it!=titulos.end(); ++it){
      cout << (*it) << endl;
    }
    cout << endl;
    cout << "Seleccione la película para la que desea crear una reserva: ";
    getline(cin >> ws, pelicula);
    try{
      infopeli = icine->seleccionarPelicula(pelicula);
    }catch(int exc){
        if (exc == 404){
          cout<<"La película " << pelicula << " no existe." << endl; 
          cout<<"Ingrese cualquier caracter para continuar...";
          cin>>buff;
          return;
        } 
    }
    list<DtCine> cines = icine->listarCines();
    cout << "La película se proyecta en los siguientes cines:" << endl;
    for(list<DtCine>::iterator it=cines.begin(); it!=cines.end(); ++it){
      cout << "\t" << (*it) << endl;
    }
    cout << "Seleccione el cine en el que desea crear la reserva: ";
    while (!(cin >> cineid)){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Por favor ingrese una opción válida: ";
    }
    list<DtFuncion> funciones = icine->seleccionarCineReserva(cineid);
    for(list<DtFuncion>::iterator it=funciones.begin(); it!=funciones.end(); ++it){
      cout << "\t" << (*it) << endl;
    }
    cout << "Seleccione la función deseada: ";
    while (!(cin >> funcid)){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Por favor ingrese una opción válida: ";
    }
    icine->seleccionarFuncion(funcid);

    cout << "Ingrese la cantidad de entradas que desea reservar: ";
    cin >> cantAsientos;
    while (!(cin >> cantAsientos)){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Por favor ingrese una cantidad válida: ";
    }
    icine->ingresarCantidadAsientos(cantAsientos);

    cout << "¿Qué metodo de pago desea utilizar? (1: Debito 2: Credito) ";
    while (!(cin >> pago) || (pago < 1 || pago > 2)){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Por favor ingrese una opción válida: ";
    }
    if (pago == 1) modopago = Deb;
    else if (pago == 2) modopago = Cred;

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
    while (!(cin >> verprecio) || verprecio != 1 || verprecio != 0){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Por favor ingrese una opción válida: ";
    }
    if (verprecio) cout << "El precio total de su reserva es de $" << icine->verPrecioTotal() << endl;

    cout << "¿Desea confirmar su reserva? 1: Si, 0: No: ";
    while (!(cin >> confirmacion) || confirmacion != 1 || confirmacion != 0){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Por favor ingrese una opción válida: ";
    }
    if (confirmacion){
      icine->confirmarReserva();
      delete icine;
      cout << "Reserva realizada. Ingrese cualquier caracter para continuar...";
      cin >> buff;
    }
    else{
      delete icine;
      cout << "Se ha cancelado la reserva. Ingrese cualquier caracter para continuar...";
      cin >> buff;
    }
  }
}

void puntuarPelicula(){
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlResenia* irese = fab->getICtrlResenia();
  int puntaje = 0;
  int opc = 0;
  string tituloPel, buff;
  if (comprobarSesion() < 1){
    cout << "Debe iniciar sesión primero. Ingrese cualquier caracter para continuar..." << endl;
    cin >> buff;
    return;
  }
  else{
    list<string> peliculas = irese->listarTitulosPeliculas();
    cout << "-Listado de películas del sistema-"<<endl;
    for(list<string>::iterator it = peliculas.begin(); it!=peliculas.end(); ++it){
      cout << (*it) << endl;
    }
    cout << endl;
    cout << "Seleccione la pelicula que desea puntuar: ";
    getline(cin >> ws, tituloPel);
    try{
      irese->seleccionarPelicula(tituloPel);
    }catch(int exc){
        if (exc == 404){
          cout<<"La película " << tituloPel << " no existe." << endl; 
          cout<<"Ingrese cualquier caracter para continuar...";
          cin>>buff;
          delete irese;
          return;
        } 
    }
    cout << "Ingrese 1 para ver su puntaje, o ingrese 2 para ingresar un puntaje: " << endl;
    while (!(cin >> opc) || (opc > 2 || opc < 1)){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Por favor ingrese una opción válida: ";
    }
    switch(opc){
      case 1:
        puntaje = irese->verPuntaje();
        if (puntaje == 0){
          cout << "Aún no has puntuado la pelicula  " << tituloPel <<". ¿Qué estás esperando?"<<endl;
          cout << "Ingrese cualquier caracter para continuar...";
          cin >> buff;
          delete irese;
        }
        else{
          cout <<"Tu puntaje para la pelicula " <<tituloPel << " es: " <<puntaje<<"/10" << endl;
          cout <<"Ingrese cualquier caracter para continuar...";
          cin >> buff;
          delete irese;
        }
        break;
      case 2:
        cout <<"Ingresa el puntaje del 1 al 10 para la pelicula "<<tituloPel << ": ";
        while (!(cin >> puntaje) || (puntaje < 1 || puntaje > 10)){
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Por favor ingrese un puntaje válido: ";
        }
        irese->ingresarPuntaje(puntaje);
        cout <<"Puntaje ingresado correctamente. Ingrese cualquier caracter para continuar...";
        cin >> buff;
        delete irese;
        break;
    }
  }
}

void comentarPelicula(){
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlResenia* irese = fab->getICtrlResenia();
  float puntaje = 0;
  string titulo, texto, buff;
  int idcom;
  ICtrlUsuario* iuser = fab->getICtrlUsuario();
  if (!iuser->checkSesion()){
    cout << "Debe iniciar sesión primero." << endl;
    return;
  }
  else{
    list<string> peliculas = irese->listarTitulosPeliculas();
    cout << "-Listado de películas del sistema-"<<endl;
    for(list<string>::iterator it = peliculas.begin(); it!=peliculas.end(); ++it){
      cout << (*it) << endl;
    }
    cout << endl;
    cout << "Seleccione la pelicula que desea comentar: ";
    getline(cin >> ws, titulo);
    try{
      irese->seleccionarPelicula(titulo);
    }catch(int exc){
        if (exc == 404){
          cout<<"La película " << titulo << " no existe." << endl; 
          cout<<"Ingrese cualquier caracter para continuar...";
          cin>>buff;
          delete irese;
          delete iuser;
          return;
        } 
    }
    bool ex;
    bool opt;
    do{
      cout << "Ingrese 0 si desea agregar un nuevo comentario, o 1 si desea responder a un comentario existente: ";
      cin >> opt;
      if (!opt){
        cout << "Ingrese su comentario: ";
        getline(cin >> ws, texto);
        irese->agregarComentario(texto);
        cout << "Su comentario se ha agregado correctamente.\n ¿Desea seguir comentando? 1: Si, 0: No: ";
        cin >> ex;
      }
      else{
        cout << "Ingrese la ID del comentario que desea responder: ";
        cin >> idcom;
        cout << "Ingrese su comentario: ";
        getline(cin >> ws, texto);
        irese->responderComentario(idcom, texto);
        cout << "Su comentario se ha agregado correctamente.\n ¿Desea seguir comentando? 1: Si, 0: No: ";
        cin >> ex;
      }
    }while(ex);
    delete irese;
    delete iuser;
    cout << "Operación terminada. Ingrese cualquier caracter para continuar..." << endl;
    cin >> buff;
  }
}

void eliminarPelicula(){}

void verInfoPelicula(){}

void verComentariosPelicula(){}

int comprobarSesion(){
  Fabrica* fab = Fabrica::getInstancia(); 
  ICtrlUsuario* iuser = fab->getICtrlUsuario();
  if (iuser->checkSesion()){
    if (iuser->checkSesionAdmin()) return 2;
    else return 1;
  }
  else return 0;
}

/*
while (!(cin >> input)){
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Por favor ingrese una opción válida: ";
}
*/