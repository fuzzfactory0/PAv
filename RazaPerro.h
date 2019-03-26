#ifndef RAZAPERRO
#define RAZAPERRO

enum RazaPerro{
  Labrador,
  Ovejero,
  Bulldog,
  Pitbull,
  Collie,
  Pekines,
  Otro};

  RazaPerro operator >>(string raza){
    switch(raza){
      case "Labrador": return Labrador; break;
      case "Ovejero": return Ovejero; break;
      case "Bulldog": return Bulldog; break;
      case "Pitbull": return Pitbull; break;
      case "Collie": return Collie; break;
      case "Pekines": return Pekines; break;
      case "Otro": return Otro; break;
    }
  }

#endif
