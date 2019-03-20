principal: Main.o Socio.o DtFecha.o Consulta.o Mascota.o Gato.o Perro.o DtConsulta.o
	g++ Socio.o Main.o DtFecha.o Consulta.o Mascota.o Gato.o Perro.o DtConsulta.o -o programa

Main.o:Main.cpp
Socio.o:Socio.cpp
DtFecha.o:DtFecha.cpp
Consulta.o:Consulta.cpp
Mascota.o:Mascota.cpp
Gato.o:Gato.cpp
Perro.o:Perro.cpp
DtConsulta.o:DtConsulta.cpp
