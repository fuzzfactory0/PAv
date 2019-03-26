#ifndef GENERO
#define GENERO

enum Genero{
  Macho,
  Hembra};


  Genero operator >>(string gen){
    switch(gen){
      case "Macho": return Macho; break;
      case "Hembra": return Hembra; break;
    }
  }

#endif
