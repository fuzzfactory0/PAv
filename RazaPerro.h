#ifndef RAZAPERRO
#define RAZAPERRO
#include <iostream>
#include <string>
using namespace std;

enum RazaPerro{
  Labrador,
  Ovejero,
  Bulldog,
  Pitbull,
  Collie,
  Pekines,
  Otro};

/*inline istream& RazaPerro::operator>>(istream& str, RazaPerro raza){
    string input;
    str >> input;

    if(input == "Labrador") raza = Labrador;
    else if (input == "Ovejero") raza = Ovejero;
    else if (input == "Bulldog") raza = Bulldog;
    else if (input == "Pitbull") raza = Pitbull;
    else if (input == "Collie") raza = Collie;
    else if (input == "Pekines") raza = Pekines;
    else if (input == "Otro") raza = Otro;
    return str;
}*/

#endif
