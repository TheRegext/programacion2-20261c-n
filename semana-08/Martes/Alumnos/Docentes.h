#pragma once
#include "Fecha.h"

class Docente{
private:///propiedades
    char _nombre[30], _apellido[30];
    int _legajo;
    Fecha _fechaIngreso;
    bool _estado;///para determinar si el alumno est� o no activo
public:
    void setLegajo(int legajo);
    int getLegajo();

    void setEstado(bool estado);
    bool getEstado();

    char* getNombre();
    void setNombre(const char* nombre);

    char* getApellido();
    void setApellido(const char* nombre);

    Fecha getFechaIngreso();
    void setFechaIngreso(Fecha f);

    void Cargar();
    void Mostrar();
    int calcularAntiguedad(Fecha fNac, Fecha fActual);

};
