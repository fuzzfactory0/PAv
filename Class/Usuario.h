#ifndef USUARIO
#define USUARIO

#include <string>

using namespace std;

class Usuario{
  private:
    string nickname;
    string avatarURL;
    string password;
    bool admin;
  public:
    Usuario();
    Usuario(string,string,string, bool);
    void setNickname(string);
    string getNickname();
    void setAvatarURL(string);
    string getAvatarURL();
    void setPassword(string);
    string getPassword();
    void setAdmin(bool);
    bool getAdmin();
    ~Usuario();
};

#endif
