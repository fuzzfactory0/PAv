#include "ICtrlUsuario.h"
#include "Fabrica.h"

using namespace std;

int main(){
  Fabrica* fab;
  ICtrlUsuario* iuser;
  iuser->cargarUsuarios();
  string nickname;
  string password;
  cout << "nickname: ";
  cin >> nickname;
  cout << "\n";
  iuser->ingresarNickname(nickname);
  cout << "password: ";
  cin >> password;

  if(iuser->verificarPassword(password)){
    iuser->iniciarSesion();
  } 


}
