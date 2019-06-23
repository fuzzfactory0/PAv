#include "Clock.h"

Clock* Clock::instancia = NULL;

Clock::Clock(){
	this->horario = Horario(12,00,00,00);
	this->fecha = Fecha(24,06,2019);
}

Clock* Clock::getInstancia(){
  if(instancia == NULL){
    instancia = new Clock();
  }
  return instancia;
}

void Clock::setHorario(Horario hor){
  this->horario = hor;
}

void Clock::setFecha(Fecha fec){
  this->fecha = fec;
}

Horario Clock::getHorario(){
  return this->horario;
}

Fecha Clock::getFecha(){
  return this->fecha;
}
void Clock::avanzarDia(){
	int dia =this->fecha.getDia();
	int mes =this->fecha.getMes();
	int anio=this->fecha.getAnio();
	if(dia==28 && mes==2){
		mes++;
		dia=1;
	}else if(dia==30 && (mes==4 || mes==6 || mes==9 || mes==11)){
		mes++;
		dia=1;
	}else if(dia==31){
		mes++;
		dia=1;
	}else{dia++;};
	if (mes==12){
		anio++;
		mes=1;
	}
	  Fecha fec = Fecha(dia,mes,anio);

	  setFecha(fec);
}

void Clock::avanzarHora(){
	int hora= this->horario.getHoraComienzo();
	int minuto=this->horario.getMinComienzo();
	hora++;
	if(hora==24){
		hora=0;
		avanzarDia();

	};



	Horario horar = Horario(hora, minuto, 0,0);
	setHorario(horar);
}

Clock::~Clock(){}
