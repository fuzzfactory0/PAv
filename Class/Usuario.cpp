#include "Usuario.h"

Usuario::Usuario(){}
Usuario::Usuario(string nickname, string avatarURL, string password){
  this->nickname = nickname;
  this->avatarURL = avatarURL;
  this->password = password;
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

string Usuario::getNickname(){
  return this->avatarURL;
}
void Usuario::setPassword(string password){
  this->password = password;
}

string Usuario::getPassword(){
  return this->password;
}
void Usuario::nombreBanco(Usuario u, string nomBanco, int cantAsientos){
  //jeje
}
void Usuario::nombreFinanciera(Usuario u, string nomFinanciera, int cantAsientos){
  //jeje
}
float Usuario::precioTotal(){
  //jeje
}
Usuario::~Usuario(){}
