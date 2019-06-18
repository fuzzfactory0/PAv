#include "Usuario.h"

Usuario::Usuario(){}
Usuario::Usuario(string nickname, string avatarURL, string password, bool admin){
  this->nickname = nickname;
  this->avatarURL = avatarURL;
  this->password = password;
  this->admin = admin;
}
void Usuario::setNickname(string nickname){
  this->nickname = nickname;
}

string Usuario::getNickname(){
  return this->nickname;
}
void Usuario::setAvatarURL(string avatarURL){
  this->avatarURL = avatarURL;
}

string Usuario::getAvatarURL(){
  return this->avatarURL;
}
void Usuario::setPassword(string password){
  this->password = password;
}

string Usuario::getPassword(){
  return this->password;
}

void Usuario::setAdmin(bool admin){
  this->admin = admin;
}

bool Usuario::getAdmin(){
  return this->admin;
}

Usuario::~Usuario(){}
