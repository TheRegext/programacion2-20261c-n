#pragma once

#include "Fecha.h"

using namespace std;

class Alumno{
private:///propiedades
    char _nombre[30], _apellido[30];
    int _legajo;
    Fecha _fechaInscripcion;
    Fecha _fechaNacimiento;
    bool _estado;///para determinar si el alumno est� o no activo
public:
    void setLegajo(int legajo);
    int getLegajo();
    void setEstado(bool estado);
    void setNombre(const char* nombre);
    void setApellido(const char* nombre);
    Fecha getFechaNacimiento();
    Fecha getFechaInscripcion();
    bool getEstado();
    void Cargar();
    void Mostrar();
    int calcularEdad(Fecha fNac, Fecha fActual);

};
