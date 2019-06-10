#include "./Interfaz/ICtrlUsuario.h"
#include "Fabrica.h"
#include <iostream>
#include <string>

using namespace std;

void menu();

int main(){
  //creación de fabrica e icontroladores
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlUsuario* iuser = fab->getICtrlUsuario();

  //Cargar usuarios al sistema
  iuser->cargarUsuarios();


  int opcion;
  menu();
  cin >> opcion;
  string nickname;
  string password;
  while(opcion != 10){
    switch(opcion){
      case 1:
        cout << "nickname: ";
        cin >> nickname;
        iuser->ingresarNickname(nickname);
        cout << "password: ";
        cin >> password;

        if(iuser->verificarPassword(password)){
          iuser->iniciarSesion();
        }
        else{
          cout << "El nombre de usuario o la contraseña son incorrectos";
        }
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        break;
      case 9:
        break;
      case 10:
        break;
      default:
        cout << "La opción ingresada no es correcta";
    }
  }

}

void menu(){
  system("clear");
  cout <<"______________________________________________________________________" <<endl;
  cout <<"******************************* MENU CINE *********************"<< endl;
  cout <<"1. Iniciar Sesión"<<endl;
  cout <<"2. Alta Cine"<<endl;
  cout <<"3. Alta Función"<<endl;
  cout <<"4. Crear Reserva"<<endl;
  cout <<"5. Puntuar Película"<<endl;
  cout <<"6. Comentar Película"<<endl;
  cout <<"7. Eliminar Película"<<endl;
  cout <<"8. Ver Información de Película"<<endl;
  cout <<"9. Ver Comentarios y Puntajes de Película"<<endl;
  cout <<"10. Salir"<<endl;
  cout <<"______________________________________________________________________" <<endl;
  cout <<"OPCION: ";
}
