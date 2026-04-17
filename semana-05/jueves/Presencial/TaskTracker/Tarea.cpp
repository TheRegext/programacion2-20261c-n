#include "Tarea.h"
#include <cstring>
#include <string>
using namespace std;

Tarea::Tarea(){
    setId(0);
    setEstado(0);
    setTitulo("");
}

Tarea::Tarea(int id, int estado, string titulo){
    setId(id);
    setEstado(estado);
    setTitulo(titulo);
    inicializarFecha(_inicio);
    inicializarFecha(_fin);

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
}
void Tarea::setTitulo(string titulo){
    strcpy(_titulo, titulo.c_str());
}
string Tarea::getNombreEstado() const{
    string nombreEstado;

    if (_estado == 1){
        nombreEstado = "Pendiente";
    }
    else if (_estado == 2){
        nombreEstado = "En curso";
    }
    else{
        nombreEstado = "Finalizada";
    }
    return nombreEstado;
}

string Tarea::toString(){

    return std::to_string(_id) + "," + _titulo + "," + getNombreEstado() + "," + _creacion.toString() + "," + _inicio.toString();

}
