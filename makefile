#Uso de variables para organización y consistencia.
#EXEC es el nombre del ejecutable generado.

OBJ=Main.o Cine.o Comentario.o Credito.o Debito.o Funcion.o Pelicula.o Puntaje.o Reserva.o Sala.o Sesion.o Usuario.o CtrlCine.o CtrlUsuario.o Direccion.o DtCine.o DtSala.o DtFuncion.o DtPelicula.o Fecha.o Horario.o HandlerCine.o HandlerPelicula.o HandlerUsuario.o Fabrica.o
EXEC=c 

main: $(OBJ)
	g++ $(OBJ) -o $(EXEC)

Cine.o: Class/Cine.cpp
Comentario.o: Class/Comentario.cpp
Credito.o: Class/Credito.cpp
Debito.o: Class/Debito.cpp
Funcion.o: Class/Funcion.cpp
Pelicula.o: Class/Pelicula.cpp
Puntaje.o: Class/Pelicula.cpp
Reserva.o: Class/Reserva.cpp
Sala.o: Class/Sala.cpp
Sesion.o: Class/Sesion.cpp
Usuario.o: Class/Usuario.cpp
CtrlCine.o: Ctrl/CtrlCine.cpp
CtrlUsuario.o: Ctrl/CtrlUsuario.cpp
Direccion.o: DT/Direccion.cpp
DtCine.o: DT/DtCine.cpp
DtSala.o: DT/DtSala.cpp
DtFuncion: DT/DtFuncion.cpp
DtPelicula.o: DT/DtPelicula.cpp
Fecha.o: DT/Fecha.cpp
Horario.o: DT/Horario.cpp
HandlerCine.o: Handler/HandlerCine.cpp
HandlerPelicula.o: Handler/HandlerPelicula.cpp
HandlerUsuario.o: Handler/HandlerUsuario.cpp
Fabrica.o: Fabrica.cpp
Main.o: main.cpp

clean:
	rm -rf *.o
	rm -rf $(EXEC)
	