#include <iostream>
#include <cstring>
#include "Alumnos.h"
#include "ArchivoMaterias.h"



using namespace std;


///////////////////////////////////////////////////////////////////////////////////////////////////
///Clase Alumno
void Alumno::setLegajo(int legajo){
        if(legajo>0){
            _legajo=legajo;
        }
    }

int Alumno::getLegajo(){
        return _legajo;
    }

void Alumno::setEstado(bool estado){
    _estado=estado;
}

bool Alumno::getEstado(){
    return _estado;
}

void Alumno::setNombre(const char* nombre){
    strcpy(_nombre, nombre);
}

void Alumno::setApellido(const char* nombre){
    strcpy(_apellido, nombre);
}

Fecha Alumno::getFechaNacimiento(){
    return _fechaNacimiento;
}

Fecha Alumno::getFechaInscripcion(){
    return _fechaInscripcion;
}

void Alumno::Cargar(){
    int auxLegajo;
    cout<<"NOMBRE: ";
    cin>>_nombre;
    cout<<"APELLIDO: ";
    cin>>_apellido;
    cout<<"LEGAJO: ";
    cin>>auxLegajo;
    setLegajo(auxLegajo);
    cout<<"FECHA DE NACIMIENTO: ";
    _fechaNacimiento.Cargar();
    cout<<"FECHA DE INSCRIPCION: ";
    _fechaInscripcion.Cargar();
    _estado=true;
}

void Alumno::Mostrar(){
    if(_estado==true){
        cout<<_nombre<<" "<<_apellido<<endl;
        cout<<"LEGAJO "<<_legajo<<endl;
        cout<<"FECHA DE NACIMIENTO ";
        _fechaNacimiento.MostrarConBarra();
        cout<<"FECHA DE INSCRIPCION ";
        _fechaInscripcion.Mostrar();
        _fechaInscripcion.MostrarConBarra();
        cout<<"ESTADO: "<<_estado<<endl;
    }
}

int Alumno::calcularEdad(Fecha fNac, Fecha fActual){
    int edad=0;

    edad=fActual.getAnio()-fNac.getAnio();

    if(fActual.getMes()<fNac.getMes()){
        edad=edad-1;
    }

    if(fActual.getMes()==fNac.getMes()){
        if(fActual.getDia()<fNac.getDia()){
            edad=edad-1;
        }
    }

    return edad;
}



