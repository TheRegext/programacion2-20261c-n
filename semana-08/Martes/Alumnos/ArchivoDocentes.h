#pragma once
#include "Docentes.h"

class ArchivoDocente{
private:
    char _nombre[30];
public:
    //CONSTRUCTOR
    ArchivoDocente(bool vacio=false, const char* nombre="docentes.dat");

    //METODOS
    bool grabarRegistro(Docente obj);
    bool bajaLogicaRegistro(int legajo);
    int buscarLegajo(int legajo);
    Docente leerRegistro(int pos);
    bool sobreEscribirRegistro(Docente reg, int pos);
    void listarActivos();
    void listar();
    int contarRegistros();
    void listarDocentesCarrera3(int idCarrera);
    void listarDocentesAntiguedad(int antig);

};

