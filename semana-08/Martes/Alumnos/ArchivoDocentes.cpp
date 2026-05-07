# include<iostream>
# include<cstring>
# include "ArchivoDocentes.h"
#include "Materias.h"
#include "ArchivoMaterias.h"

using namespace std;

int ArchivoDocente::contarRegistros(){
    FILE *p;
    p=fopen(_nombre, "rb");
    if(p==nullptr)return 0;
    fseek(p,0,2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof(Docente);
}

ArchivoDocente::ArchivoDocente(bool vacio, const char* nombre){
    strcpy(_nombre,nombre);
    if(vacio==true){
      FILE *p=fopen(nombre,"wb");
        fclose(p);
    }
}


bool ArchivoDocente::grabarRegistro(Docente obj){
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

bool ArchivoDocente::sobreEscribirRegistro(Docente reg, int pos){
    FILE *pAlu=fopen(_nombre, "rb+");///+ le agrega al modo lo que le falta

    if(pAlu==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return false;
    }

    ///archivo --> 8 bytes: puntero va a quedar en el byte 8. (posicion 0)
    ///archivo --> 8 bytes: puntero va a quedar en el byte 16 (posicion 1)
    //cada registro pesa 8 bytes.
    //yo encontr� con buscarRegistro() el registro en el 4� registro.
    //8 x 4 = 32 bytes

    fseek(pAlu,pos*sizeof reg,0); ///SEEK_SET->0 PRINCIPIO; SEEK_CUR->1 POSICION ACTUAL; SEEK_END->2 FINAL DEL ARCHIVO

    bool escribio=fwrite(&reg, sizeof reg, 1, pAlu);

    fclose(pAlu);

    return escribio;
}


int ArchivoDocente::buscarLegajo(int legajo){
    Docente reg;
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



Docente ArchivoDocente::leerRegistro(int pos){
    Docente reg;

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

bool ArchivoDocente::bajaLogicaRegistro(int legajo){
    Docente reg;

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



void ArchivoDocente::listar(){
    Docente obj;
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

void ArchivoDocente::listarActivos(){
    Docente obj;
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

void ArchivoDocente::listarDocentesCarrera3(int idCarrera){
    ///HACER UN MÉTODO QUE LISTE A LOS DOCENTES DE LA CARRERA 3

    //1° recorro uno a uno los registros de docente
    //una vez que leo el primero, tomo el legajo y busco en archivo materias que coincida el legajo
    //y el código de carrera


    Docente obj;
    ArchivoMateria arMat;
    ArchivoDocente arDoc;

    FILE *pDoc;

    pDoc=fopen(_nombre,"rb");

    if(pDoc==nullptr){
        return;
    }

    while(fread(&obj, sizeof obj, 1,pDoc)!=0){
        if(arMat.buscarDocentePorLegajoYCarrera(obj.getLegajo(),idCarrera)){
            obj.Mostrar();
            cout<<endl;
        }
    }

    fclose(pDoc);
}

void ArchivoDocente::listarDocentesAntiguedad(int antig){
    Docente obj;
    ArchivoDocente arDoc;

    FILE *pDoc;

    pDoc=fopen(_nombre,"rb");

    if(pDoc==nullptr){
        return;
    }

    Fecha factual(6,5,2026);

    while(fread(&obj, sizeof obj, 1,pDoc)!=0){
        //por cada registro tengo que ver si la antiguedad es mayor o igual a 10
        int ant=obj.calcularAntiguedad(obj.getFechaIngreso(),factual);
        if(ant>=antig){
            obj.Mostrar();
            cout<<endl;
        }
    }

    fclose(pDoc);


}
