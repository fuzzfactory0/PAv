#ifndef USUARIO
#define USUARIO

#include <iostream>
using namespace std;

class Usuario{
  private:
    string nickname;
    string avatarURL;
    string password;
  public:
    Usuario();
    Usuario(string,string,string);
    void setNickname(string);
    string getNickname();
    void setAvatarURL(string);
    string getAvatarURL();
    void setPassword(string);
    string getPassword();
    void nombreBanco(Usuario,string, int);
    void nombreFinanciera(Usuario, string, int);
    float precioTotal ();
    ~Usuario();
};

#endif
