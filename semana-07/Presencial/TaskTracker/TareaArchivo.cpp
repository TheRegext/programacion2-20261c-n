#include "TareaArchivo.h"
#include "Tarea.h"
#include <string>
#include <cstdio>
using namespace std;

TareaArchivo::TareaArchivo()
{
    _nombreArchivo = "tareas.dat";
}
TareaArchivo::TareaArchivo(string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}
bool TareaArchivo::Guardar(Tarea tarea){
    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "ab");

    if (p == NULL){
        return false;
    }

    bool escribio = fwrite(&tarea, sizeof(Tarea), 1, p);
    fclose(p);
    return escribio;
}
bool TareaArchivo::Guardar(Tarea tarea, int posicion){
    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb+");

    if (p == NULL){
        return false;
    }

    fseek(p, posicion * sizeof(Tarea), SEEK_SET);
    bool escribio = fwrite(&tarea, sizeof(Tarea), 1, p);
    fclose(p);
    return escribio;
}

int TareaArchivo::Buscar(int idTarea){
    int cant = getCantidadRegistros();

    if (cant == 0){
        return -2;
    }

    for(int i=0; i<cant; i++){
        Tarea reg = Leer(i);
        if (reg.getId() == idTarea){
            return i;
        }
    }

    return -1;

}

int TareaArchivo::getCantidadRegistros(){
    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");

    if (p == NULL){
       return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Tarea);
}

Tarea TareaArchivo::Leer(int posicion){
    Tarea aux;
    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");

    if (p == NULL){
        return aux;
    }
    fseek(p, posicion * sizeof(Tarea), SEEK_SET);
    fread(&aux, sizeof(Tarea), 1, p);
    fclose(p);
    return aux;
}

void TareaArchivo::Leer(int cantidadALeer, Tarea *vec){
    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "rb");

    if (p == NULL){
        return;
    }
    fread(vec, sizeof(Tarea), cantidadALeer, p);
    fclose(p);
}

bool TareaArchivo::Truncar(){
    FILE *p;
    p = fopen(_nombreArchivo.c_str(), "wb");

    if (p == NULL){
        return false;
    }

    fclose(p);
    return true;
}


