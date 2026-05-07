# include<iostream>
# include<cstring>
#include "ArchivoAlumnos.h"

using namespace std;

int archivoAlumno::contarRegistros(){
    FILE *p;
    p=fopen(_nombre, "rb");
    if(p==nullptr)return 0;
    fseek(p,0,2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof(Alumno);
}

archivoAlumno::archivoAlumno(bool vacio, const char* nombre){
    strcpy(_nombre,nombre);
    if(vacio==true){
      FILE *p=fopen(nombre,"wb");
        fclose(p);
    }
}


bool archivoAlumno::grabarRegistro(Alumno obj){
    FILE *pAlu;

    pAlu=fopen(_nombre,"ab");

    if(pAlu==nullptr){
        //cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    bool escribio=fwrite(&obj, sizeof obj, 1,pAlu);

    fclose(pAlu);

    return escribio;

}

bool archivoAlumno::sobreEscribirRegistro(Alumno reg, int pos){
    FILE *pAlu=fopen(_nombre, "rb+");///+ le agrega al modo lo que le falta

    if(pAlu==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return false;
    }

    fseek(pAlu,pos*sizeof reg,0); ///SEEK_SET->0 PRINCIPIO; SEEK_CUR->1 POSICION ACTUAL; SEEK_END->2 FINAL DEL ARCHIVO

    bool escribio=fwrite(&reg, sizeof reg, 1, pAlu);

    fclose(pAlu);

    return escribio;
}


int archivoAlumno::buscarLegajo(int legajo){
    Alumno reg;
    int posicion=0;
    FILE *pAlu=fopen(_nombre, "rb");

    if(pAlu==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return -1;
    }

    while(fread(&reg, sizeof reg, 1, pAlu)==1){
        if(legajo==reg.getLegajo()){
            fclose(pAlu);
            return posicion;
        }
        posicion++;
    }

    fclose(pAlu);

    return -1;
}

void archivoAlumno::buscarTodosPorEdad(int edad, Fecha fechaActual){
    Alumno obj;
    FILE *pAlu;

    pAlu=fopen(_nombre,"rb");

    if(pAlu==nullptr){
        return;
    }

    while(fread(&obj, sizeof obj, 1,pAlu)!=0){
        if(obj.calcularEdad(obj.getFechaNacimiento(), fechaActual)==edad){
            obj.Mostrar();
            cout<<endl;
        }
    }

    fclose(pAlu);
}

void archivoAlumno::buscarTodosPorAnioInscripcion(int a){
    Alumno obj;
    FILE *pAlu;

    pAlu=fopen(_nombre,"rb");

    if(pAlu==nullptr){
        return;
    }

    while(fread(&obj, sizeof obj, 1,pAlu)!=0){
        if(obj.getFechaInscripcion().getAnio()==a){
            obj.Mostrar();
            cout<<endl;
        }
    }

    fclose(pAlu);

}


Alumno archivoAlumno::leerRegistro(int pos){
    Alumno reg;

    FILE *pAlu=fopen(_nombre, "rb");

    if(pAlu==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        //reg.setLegajo(-2);
        return reg;
    }

    fseek(pAlu,pos*sizeof reg,0); ///SEEK_SET->0 PRINCIPIO; SEEK_CUR->1 POSICION ACTUAL; SEEK_END->2 FINAL DEL ARCHIVO

    fread(&reg, sizeof reg, 1, pAlu);

    fclose(pAlu);

    return reg;
}

bool archivoAlumno::bajaLogicaRegistro(int legajo){
    Alumno reg;

    int pos=buscarLegajo(legajo);

    if(pos==-1){
        cout<<"EL LEGAJO NO EXISTE "<<endl;
        system("pause");
        return false;
    }

    reg=leerRegistro(pos);

    reg.setEstado(false);

    return sobreEscribirRegistro(reg, pos);
}



void archivoAlumno::listar(){
    Alumno obj;
    FILE *pAlu;

    pAlu=fopen(_nombre,"rb");

    if(pAlu==nullptr){
        //cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, sizeof obj, 1,pAlu)!=0){
        obj.Mostrar();
        cout<<endl;
    }

    fclose(pAlu);
}

void archivoAlumno::listarActivos(){
    Alumno obj;
    FILE *pAlu;

    pAlu=fopen(_nombre,"rb");

    if(pAlu==nullptr){
        //cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, sizeof obj, 1,pAlu)!=0){
        if(obj.getEstado()){
            obj.Mostrar();
        }
        cout<<endl;
    }

    fclose(pAlu);
}
