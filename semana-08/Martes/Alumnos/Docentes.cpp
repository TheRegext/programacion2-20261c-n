# include<iostream>
# include<cstring>
#include "Docentes.h"

using namespace std;

void Docente::setLegajo(int legajo){
            if(legajo>0){
                _legajo=legajo;
            }
        }

    int Docente::getLegajo(){
            return _legajo;
        }

    void Docente::setEstado(bool estado){
        _estado=estado;
    }

    bool Docente::getEstado(){
        return _estado;
    }

    char* Docente::getNombre(){
        return _nombre;
    }

    void Docente::setNombre(const char* nombre){
        strcpy(_nombre, nombre);
    }

    char* Docente::getApellido(){
        return _apellido;
    }

    void Docente::setApellido(const char* nombre){
        strcpy(_apellido, nombre);
    }

    Fecha Docente::getFechaIngreso(){
        return _fechaIngreso;
    }
    void Docente::setFechaIngreso(Fecha f){
        _fechaIngreso=f;
    }



    void Docente::Cargar(){
        int auxLegajo;
        cout<<"NOMBRE: ";
        cin>>_nombre;
        cout<<"APELLIDO: ";
        cin>>_apellido;
        cout<<"LEGAJO: ";
        cin>>auxLegajo;
        setLegajo(auxLegajo);
        _fechaIngreso.Cargar();
        _estado=true;
    }

    void Docente::Mostrar(){
        if(_estado==true){
            cout<<_nombre<<" "<<_apellido<<endl;
            cout<<"LEGAJO "<<_legajo<<endl;
            _fechaIngreso.Mostrar();
            cout<<"ESTADO: "<<_estado<<endl;
        }
    }

int Docente::calcularAntiguedad(Fecha fNac, Fecha fActual){
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


