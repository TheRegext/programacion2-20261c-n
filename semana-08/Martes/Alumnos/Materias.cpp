# include<iostream>
# include<cstring>
#include "Materias.h"
#include "ArchivoMaterias.h"
#include "Docentes.h"
#include "ArchivoDocentes.h"

using namespace std;


///Class Materia
Materia::Materia(){
        _codMateria=-1;
        _idCarrera=-1;
        strcpy(_nombre,"vacio");
        _horas=-1;
        _legajoDocente=-1;
        _cuatrimestral=-1;
        _estado=0;

    }
Materia::Materia(int materia, int idCarrera, char* nombre, int horas, int legDoc, bool cuatri, bool estado){
        _codMateria=materia;
        _idCarrera=idCarrera;
        strcpy(_nombre,nombre);
        _horas=horas;
        _legajoDocente=legDoc;
        _cuatrimestral=cuatri;
        _estado=estado;
    }

    //METDOS
    int Materia::getCodMateria(){return _codMateria;}
    int Materia::getIdCarrera(){return _idCarrera;}
    char* Materia::getNombre(){return _nombre;}
    int Materia::getHoras(){return _horas;}
    int Materia::getLegajoDocente(){return _legajoDocente;}
    bool Materia::getEsCuatrimestral(){return _cuatrimestral;}
    bool Materia::getEstado(){return _estado;}

    void Materia::setCodMateria(int codMat){
        _codMateria=codMat;
    }
    void Materia::setIdCarrera(int idCarr){
        _idCarrera=idCarr;
    }
    void Materia::setNombreMateria(char* nomMat){
        strcpy(_nombre,nomMat);
    }
    void Materia::setHoras(int horas){
        _horas=horas;
    }
    void Materia::setLegajoDocente(int legDoc){
        _legajoDocente=legDoc;
    }
    void Materia::setEsCuatrimestral(bool esCuat){
        _cuatrimestral=esCuat;
    }
    void Materia::setEstado(bool estado){
        _estado=estado;
    }

    void Materia::Mostrar(){
        Docente doc;
        ArchivoDocente arDoc;

        cout<<"Id. Carrera: "<<_idCarrera<<endl;    ///--> ACÁ VAMOS A VER COMO UNIR ARCHIVOS.
        cout<<"Cod. Materia: "<<_codMateria<<endl;
        cout<<"Nombre de la materia: "<<_nombre<<endl;
        cout<<"Horas: "<<_horas<<endl;

        ///CÓMO HACEMOS PARA QUE ACÁ APAREZCA EL NOMBRE DEL DOCENTE EN VEZ DEL LEGAJO?
        cout<<"Legajo profesor: "<<_legajoDocente<<endl;  ///--> ACÁ VAMOS A VER COMO UNIR ARCHIVOS.

        int pos=arDoc.buscarLegajo(_legajoDocente);

        if(pos>=0){

            doc=arDoc.leerRegistro(pos);

            cout<<"Nombre docente: "<<doc.getNombre()<<endl;
            cout<<"Apellido docente: "<<doc.getApellido()<<endl;
        }


        cout<<"Cuatrimestral?: ";
        if(_cuatrimestral){
            cout<<"Si."<<endl;
        }
        else{
            cout<<"No."<<endl;
        }
        cout<<"Estado: ";
        if(_estado){
            cout<<"Activa."<<endl;
        }
        else{
            cout<<"Inactiva."<<endl;
        }

    }
    void Materia::Cargar(){
        ArchivoMateria arMat;
        int aux;
        char auxN[20];
        bool auxB;


        cout<<"Id. Carrera: ";
        cin>>aux;
        setIdCarrera(aux);

        cout<<"Cod. Materia: ";
        //cin>>aux;
        setCodMateria(arMat.proximoIdPorCarrera(aux));
        cout<<_codMateria<<endl;

        cout<<"Nombre de la materia: ";
        cin>>auxN;
        setNombreMateria(auxN);

        cout<<"Horas: ";
        cin>>aux;
        setHoras(aux);

        cout<<"Legajo Profesor: ";
        cin>>aux;

        ///COMO HACEMOS PARA QUE NO ME PERMITA CARGAR DOCENTES QUE NO EXISTEN?
        Docente doc;
        ArchivoDocente arDoc;

        int pos=arDoc.buscarLegajo(aux);

        while(pos==-1){
            cout<<"El docente no existe, reingrese legajo: "<<endl;
            cin>>aux;
            pos=arDoc.buscarLegajo(aux);
        }


        setLegajoDocente(aux);

        cout<<"Cuatrimestral? (1- SI / 0- NO): ";
        cin>>auxB;
        setEsCuatrimestral(auxB);

        _estado=true;
    }


