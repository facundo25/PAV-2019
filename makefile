principal: Consulta.o  DtConsulta.o DtFecha.o DtGato.o  DtMascota.o DtPerro.o Gato.o main.o Mascota.o Perro.o RazaPerro.o Socio.o
	g++ Consulta.o  DtConsulta.o DtFecha.o DtGato.o  DtMascota.o DtPerro.o Gato.o main.o Mascota.o Perro.o RazaPerro.o Socio.o -o veterinaria

Consulta.o: Consulta.cpp

DtConsulta.o: DtConsulta.cpp

DtFecha.o: DtFecha.cpp

DtGato.o: DtGato.cpp

DtMascota.o: DtMascota.cpp

DtPerro.o: DtPerro.cpp

Gato.o: Gato.cpp

main.o: main.cpp

Mascota.o: Mascota.cpp

Perro.o: Perro.cpp

RazaPerro.o: RazaPerro.cpp

Socio.o: Socio.cpp

clean: 
	rm -rf *.o veterinaria
