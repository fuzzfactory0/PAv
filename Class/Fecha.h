#ifndef FECHA
#define FECHA

class Fecha{
  private:
    int dia;
    int mes;
    int anio;
  public:
    Fecha();
    Fecha(int,int,int);
    void setDia(int);
    int getDia();
    void setMes(int);
    int getMes();
    void setAnio(int);
    int getAnio();
    ~Fecha();
};

#endif
