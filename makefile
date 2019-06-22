OTH=main.o Fabrica.o Clock.o
CLASS=Class/Cine.o Class/Comentario.o Class/Credito.o Class/Debito.o Class/Funcion.o Class/Pelicula.o Class/Puntaje.o Class/Reserva.o Class/Sala.o Class/Sesion.o Class/Usuario.o
DT=DT/Direccion.o DT/DtCine.o DT/DtComentario.o DT/DtSala.o DT/DtFuncion.o DT/DtPelicula.o DT/Fecha.o DT/Horario.o
HANDLER=Handler/HandlerCine.o Handler/HandlerPelicula.o Handler/HandlerUsuario.o
CTRL=Ctrl/CtrlCine.o Ctrl/CtrlResenia.o Ctrl/CtrlPelicula.o Ctrl/CtrlUsuario.o
EXEC=c
OBJ=$(OTH) $(CLASS) $(DT) $(CTRL) $(HANDLER)

main: $(OBJ)
	g++ $(OBJ) -o $(EXEC)
	clear
	./$(EXEC)

Class/Cine.o: Class/Cine.cpp
Class/Comentario.o: Class/Comentario.cpp
Class/Credito.o: Class/Credito.cpp
Class/Debito.o: Class/Debito.cpp
Class/Funcion.o: Class/Funcion.cpp
Class/Pelicula.o: Class/Pelicula.cpp
Class/Puntaje.o: Class/Pelicula.cpp
Class/Reserva.o: Class/Reserva.cpp
Class/Sala.o: Class/Sala.cpp
Class/Sesion.o: Class/Sesion.cpp
Class/Usuario.o: Class/Usuario.cpp
Ctrl/CtrlCine.o: Ctrl/CtrlCine.cpp
Ctrl/CtrlResenia.o: Ctrl/CtrlResenia.cpp
Ctrl/CtrlPelicula.o: Ctrl/CtrlPelicula.cpp
Ctrl/CtrlUsuario.o: Ctrl/CtrlUsuario.cpp
DT/Direccion.o: DT/Direccion.cpp
DT/DtComentario.o: DT/DtComentario.cpp
DT/DtCine.o: DT/DtCine.cpp
DT/DtSala.o: DT/DtSala.cpp
DT/DtFuncion.o: DT/DtFuncion.cpp
DT/DtPelicula.o: DT/DtPelicula.cpp
DT/Fecha.o: DT/Fecha.cpp
DT/Horario.o: DT/Horario.cpp
Handler/HandlerCine.o: Handler/HandlerCine.cpp
Handler/HandlerPelicula.o: Handler/HandlerPelicula.cpp
Handler/HandlerUsuario.o: Handler/HandlerUsuario.cpp
Fabrica.o: Fabrica.cpp
Clock.o: Clock.cpp
main.o: main.cpp

clean:
	find . -name '*.o' -delete
	rm -rf $(EXEC)
