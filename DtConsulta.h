#ifndef DTCONSULTA
#define DTCONSULTA

class DtConsulta{
  private:
    DtFecha fechaConsulta;
    string motivo;
  public:
    DtConsulta();
    DtConsulta(DtFecha fechaConsulta, string motivo);
    DtFecha getFechaConsulta();
    void setFechaConsulta(DtFecha);
    string getMotivo();
    void setMotivo(string);
    ~DtConsulta();
};

#endif
