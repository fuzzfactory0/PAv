#ifndef TIPOPELO
#define TIPOPELO
#include <iostream>
#include <string>
using namespace std;

enum TipoPelo{
  Corto,Mediano,
  Largo};

/*inline istream& TipoPelo::operator>>(istream& str, TipoPelo pelo){
    string input;
    str >> input;

    if(input == "Corto") pelo = Corto;
    else if (input == "Mediano") pelo = Mediano;
    else if (input == "Largo") pelo = Largo;
    return str;
}*/
#endif
