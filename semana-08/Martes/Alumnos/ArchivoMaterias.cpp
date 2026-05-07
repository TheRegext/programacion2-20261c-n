# include<iostream>
# include<cstring>
#include "ArchivoMaterias.h"

using namespace std;

ArchivoMateria::ArchivoMateria(bool vacio, const char* nombre){
    strcpy(_nombre,nombre);
    if(vacio==true){
      FILE *p=fopen(nombre,"wb");
        fclose(p);
    }
}

bool ArchivoMateria::grabarRegistro(Materia obj){
    FILE *pMat;

    pMat=fopen(_nombre,"ab");

    if(pMat==nullptr){
        //cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    bool escribio=fwrite(&obj, sizeof obj, 1,pMat);

    fclose(pMat);

    return escribio;

}

bool ArchivoMateria::sobreEscribirRegistro(Materia reg, int pos){
    FILE *pMat=fopen(_nombre, "rb+");///+ le agrega al modo lo que le falta

    if(pMat==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return false;
    }

    fseek(pMat,pos*sizeof reg,0); ///SEEK_SET->0 PRINCIPIO; SEEK_CUR->1 POSICION ACTUAL; SEEK_END->2 FINAL DEL ARCHIVO

    bool escribio=fwrite(&reg, sizeof reg, 1, pMat);

    fclose(pMat);

    return escribio;
}

int ArchivoMateria::buscarMateriaId(int idCarrera, int codMateria){
    Materia reg;
    int posicion=0;
    FILE *pMat=fopen(_nombre, "rb");

    if(pMat==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return -1;
    }

    while(fread(&reg, sizeof reg, 1, pMat)==1){
        if(idCarrera==reg.getIdCarrera() && codMateria==reg.getCodMateria()){
            fclose(pMat);
            return posicion;
        }
        posicion++;
    }

    fclose(pMat);

    return -1;
}

Materia ArchivoMateria::leerRegistro(int pos){
    Materia reg;

    FILE *pMat=fopen(_nombre, "rb");

    if(pMat==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return reg;
    }

    fseek(pMat,pos*sizeof reg,0); ///SEEK_SET->0 PRINCIPIO; SEEK_CUR->1 POSICION ACTUAL; SEEK_END->2 FINAL DEL ARCHIVO

    fread(&reg, sizeof reg, 1, pMat);

    fclose(pMat);

    return reg;
}

bool ArchivoMateria::bajaLogicaRegistro(int idCarr, int codMat){
    Materia reg;

    int pos=buscarMateriaId(idCarr, codMat);

    if(pos==-1){
        cout<<"LA MATERIA NO EXISTE "<<endl;
        system("pause");
        return false;
    }

    reg=leerRegistro(pos);

    reg.setEstado(false);

    return sobreEscribirRegistro(reg, pos);
}

void ArchivoMateria::listar(){
    Materia obj;
    FILE *pMat;

    pMat=fopen(_nombre,"rb");

    if(pMat==nullptr){
        //cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, sizeof obj, 1,pMat)!=0){
        obj.Mostrar();
        cout<<endl;
    }

    fclose(pMat);
}

int ArchivoMateria::contarRegistros(){
    FILE *p;
    p=fopen(_nombre, "rb");
    if(p==nullptr)return 0;
    fseek(p,0,2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof(Materia);
}

int ArchivoMateria::contarRegistrosPorCarrera(int idCarr){
    Materia obj;
    int contador=0;
    FILE *pMat;

    pMat=fopen(_nombre,"rb");

    if(pMat==nullptr){
        return contador;
    }

    while(fread(&obj, sizeof obj, 1,pMat)!=0){
        if(obj.getIdCarrera()==idCarr){
            contador++;
        }
    }

    fclose(pMat);
    return contador;
}

int ArchivoMateria::proximoIdPorCarrera(int idCarr){

    return contarRegistrosPorCarrera(idCarr)+1;
}

bool ArchivoMateria::buscarDocentePorLegajoYCarrera(int legajoDocente, int idCarrera){
    Materia reg;
    FILE *pMat=fopen(_nombre, "rb");

    if(pMat==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return false;
    }

    while(fread(&reg, sizeof reg, 1, pMat)==1){
        if(reg.getLegajoDocente()==legajoDocente && reg.getIdCarrera()==idCarrera){
            fclose(pMat);
            return true;
        }
    }

    fclose(pMat);

    return false;
}

void ArchivoMateria::listarMateriasCarrera(int idCarrera){
    Materia obj;
    FILE *pMat;

    pMat=fopen(_nombre,"rb");

    if(pMat==nullptr){
        //cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, sizeof obj, 1,pMat)!=0){
        if(obj.getIdCarrera()==idCarrera && obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }

    fclose(pMat);


}

