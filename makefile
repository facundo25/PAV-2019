principal:  DtConsulta.o DtFecha.o DtGato.o  DtMascota.o DtPerro.o Gato.o main.o Mascota.o Perro.o Socio.o Consulta.o
	g++ DtConsulta.o DtFecha.o DtGato.o  DtMascota.o DtPerro.o Gato.o main.o Mascota.o Perro.o Socio.o Consulta.o -o veterinaria

DtConsulta.o: dataType/DtConsulta.cpp
	g++ -c dataType/DtConsulta.cpp -o DtConsulta.o

DtFecha.o: dataType/DtFecha.cpp
	g++ -c dataType/DtFecha.cpp -o DtFecha.o

DtGato.o: dataType/DtGato.cpp
	g++ -c dataType/DtGato.cpp -o DtGato.o

DtMascota.o: dataType/DtMascota.cpp
	g++ -c dataType/DtMascota.cpp -o DtMascota.o

DtPerro.o: dataType/DtPerro.cpp
	g++ -c dataType/DtPerro.cpp -o DtPerro.o

Gato.o: clases/Gato.cpp
	g++ -c clases/Gato.cpp -o Gato.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

Mascota.o: clases/Mascota.cpp
	g++ -c clases/Mascota.cpp -o Mascota.o

Perro.o: clases/Perro.cpp
	g++ -c clases/Perro.cpp -o Perro.o

Socio.o: clases/Socio.cpp
	g++ -c clases/Socio.cpp -o Socio.o

Consulta.o: clases/Consulta.cpp
	g++ -c clases/Consulta.cpp -o Consulta.o

clean:
	rm -rf *.o veterinaria
