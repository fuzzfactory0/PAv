principal: Main.o Socio.o DtFecha.o Consulta.o Mascota.o Gato.o Perro.o DtConsulta.o DtMascota.o DtPerro.o DtGato.o
	g++ Socio.o Main.o DtFecha.o Consulta.o Mascota.o Gato.o Perro.o DtConsulta.o DtMascota.o DtPerro.o DtGato.o -o p

Main.o:Main.cpp
Socio.o:Socio.cpp
DtFecha.o:DtFecha.cpp
Consulta.o:Consulta.cpp
Mascota.o:Mascota.cpp
Gato.o:Gato.cpp
Perro.o:Perro.cpp
DtConsulta.o:DtConsulta.cpp
DtMascota.o: DtMascota.cpp
DtPerro.o:DtPerro.cpp
DtGato.o: DtGato.cpp

clean:
	rm -rf *.o
	rm -rf p
