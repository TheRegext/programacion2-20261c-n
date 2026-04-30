#include "Tarea.h"
#include <cstring>
#include <string>
using namespace std;

Tarea::Tarea(){
    setId(0);
    setEstado(0);
    setTitulo("");
    setEliminado(false);
}

Tarea::Tarea(int id, int estado, string titulo){
    setId(id);
    setEstado(estado);
    setTitulo(titulo);
    inicializarFecha(_inicio);
    inicializarFecha(_fin);
    setEliminado(false);
}

void Tarea::inicializarFecha(Fecha &f){
    f.setDia(0);
    f.setMes(0);
    f.setAnio(0);
}

int Tarea::getId() const{
    return _id;
}
int Tarea::getEstado() const{
    return _estado;
}
string Tarea::getTitulo() const{
    return _titulo;
}

void Tarea::setId(int id){
    _id = id;
}
void Tarea::setEstado(int estado){
    _estado = estado;

    if (estado == 1){
        _inicio = Fecha();
    }
    else if (estado == 2){
        _fin = Fecha();
    }

}
void Tarea::setTitulo(string titulo){
    strcpy(_titulo, titulo.c_str());
}
string Tarea::getNombreEstado() const{
    string nombreEstado;

    if (_estado == 0){
        nombreEstado = "Pendiente";
    }
    else if (_estado == 1){
        nombreEstado = "En curso";
    }
    else if (_estado == 2){
        nombreEstado = "Finalizada";
    }
    else{
        nombreEstado = "Incorrecto";
    }
    return nombreEstado;
}

string Tarea::toString(){

    return std::to_string(_id) + "," + _titulo + "," + getNombreEstado() + "," + _creacion.toString() + "," + _inicio.toString();

}

void Tarea::setInicio(Fecha f){
    _inicio = f;
}
void Tarea::setFin(Fecha f){
    _fin = f;
}

Fecha Tarea::getInicio(){
    return _inicio;
}
Fecha Tarea::getFin(){
    return _fin;
}
Fecha Tarea::getCreacion(){
    return _creacion;
}

bool Tarea::getEliminado() const {
    return _eliminado;
}

void Tarea::setEliminado(bool eliminado){
    _eliminado = eliminado;
}



