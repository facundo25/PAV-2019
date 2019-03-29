cmake_minimum_required(VERSION 3.13)
project(PAV_2019)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PAV_2019
        clases/Consulta.cpp
        clases/Consulta.h
        dataType/DtConsulta.cpp
        dataType/DtConsulta.h
        dataType/DtFecha.cpp
        dataType/DtFecha.h
        dataType/DtGato.cpp
        dataType/DtGato.h
        dataType/DtMascota.cpp
        dataType/DtMascota.h
        dataType/DtPerro.cpp
        dataType/DtPerro.h
        clases/Gato.cpp
        clases/Gato.h
        enum/Genero.h
        main.cpp
        clases/Mascota.cpp
        clases/Mascota.h
        clases/Perro.cpp
        clases/Perro.h
        enum/RazaPerro.h
        clases/Socio.cpp
        clases/Socio.h
        enum/TipoPelo.h)
