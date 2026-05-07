#pragma once

#include <cstring>
#include "Alumnos.h"
#include "Fecha.h"


class archivoAlumno{
private:
    char _nombre[30];
public:
    //CONSTRUCTOR
    archivoAlumno(bool vacio=false, const char* nombre="alumnos.dat");

    //METODOS
    bool grabarRegistro(Alumno obj);
    bool bajaLogicaRegistro(int legajo);
    int buscarLegajo(int legajo);
    void buscarTodosPorEdad(int edad, Fecha fechaActual);
    void buscarTodosPorAnioInscripcion(int a);
    Alumno leerRegistro(int pos);
    bool sobreEscribirRegistro(Alumno reg, int pos);
    void listarActivos();
    void listar();
    int contarRegistros();
};

