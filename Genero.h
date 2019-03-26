#ifndef GENERO
#define GENERO
#include <iostream>
using namespace std;

enum Genero{
  Macho,
  Hembra};

/*inline istream& Genero::operator>>(istream& str, Genero gen){
    string input;
    str >> input;

    if(input == "Macho") gen = Macho;
    else if(input == "Hembra") gen = Hembra;
    return str;
}*/

#endif
