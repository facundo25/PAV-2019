cmake_minimum_required(VERSION 3.12)
project(PAV-2019)

set(CMAKE_CXX_STANDARD 14)

add_executable(PAV-2019

        main.cpp

        Genero.h
        RazaPerro.h
        TipoPelo.h

        Mascota.cpp
        Mascota.h
        Socio.cpp
        Socio.h

        DtFecha.cpp
        DtFecha.h
        perro.h Consulta.h Consulta.cpp Gato.h Perro.cpp Gato.cpp)
