#ifndef USUARIO
#define USUARIO

#include <string>

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
    ~Usuario();
};

#endif
