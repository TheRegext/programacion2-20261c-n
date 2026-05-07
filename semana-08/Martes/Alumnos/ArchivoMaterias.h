#pragma once
#include "Materias.h"

class ArchivoMateria{
private:
    char _nombre[30];
public:
    //CONSTRUCTOR
    ArchivoMateria(bool vacio=false, const char* nombre="materias.dat");

    //METODOS
    bool grabarRegistro(Materia obj);
    bool bajaLogicaRegistro(int idCarrera, int codMateria);
    int buscarMateriaId(int idCarrera, int codMateria);
    Materia leerRegistro(int pos);
    bool sobreEscribirRegistro(Materia reg, int pos);
    void listar();
    int contarRegistros();
    int contarRegistrosPorCarrera(int idCarr);
    int proximoIdPorCarrera(int idCarr);
    bool buscarDocentePorLegajoYCarrera(int legajoDocente, int idCarrera);
    void listarMateriasCarrera(int idCarrera);
};

