#ifndef TIPOPELO
#define TIPOPELO

enum TipoPelo{
  Corto,Mediano,
  Largo};

  TipoPelo operator >>(string pelo){
    switch(pelo){
      case "Corto": return Corto; break;
      case "Mediano": return Mediano; break;
      case "Largo": return Largo; break;
    }
  }

#endif
