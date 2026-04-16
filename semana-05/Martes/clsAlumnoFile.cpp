///Fecha:
///Autor:
///Comentario:

#include <iostream>
#include <cstring>

using namespace std;
///clase Fecha
class Fecha{
private:///variables de la clase
    int dia, mes, anio;
public:
    Fecha(int d, int m, int a);
    void setDia(int _dia){
        if(_dia>=1 && _dia<=31)dia=_dia;
    }
    int getDia(){return dia;}
    void Cargar(){
        cout<<"DIA ";
        cin>>dia;
        cout<<"MES ";
        cin>>mes;
        cout<<"ANIO ";
        cin>>anio;
    }
    void Mostrar();///prototipo del método
    void MostrarConBarra();
};

Fecha::Fecha(int d=1, int m=2, int a=3){
    dia=d;
    mes=m;
    anio=a;
}

void Fecha::Mostrar(){
    cout<<"DIA "<<dia<<endl;
    cout<<"MES "<<mes<<endl;
    cout<<"ANIO "<<anio<<endl;
}
void Fecha::MostrarConBarra(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
///Fin clase Fecha

///Clase Alumno
class Alumno{
private:///propiedades
    char nombre[30], apellido[30];
    int legajo;
    Fecha fechaInscripcion;
    Fecha fechaNacimiento;
public:
    void Cargar();
    void Mostrar();
};

void Alumno::Cargar(){
    cout<<"NOMBRE ";
    cin>>nombre;
    cout<<"APELLIDO ";
    cin>>apellido;
    cout<<"LEGAJO ";
    cin>>legajo;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.Cargar();
    cout<<"FECHA DE INSCRIPCION ";
    fechaInscripcion.Cargar();
}

void Alumno::Mostrar(){
    cout<<nombre<<" "<<apellido<<endl;
    cout<<"LEGAJO "<<legajo<<endl;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.MostrarConBarra();
    cout<<"FECHA DE INSCRIPCION ";
    fechaInscripcion.MostrarConBarra();
}

///Fin clase Alumno

///Materia: nombre de la materia, horas, código, profesor, idCarrera, codigo, cuatri/anual
///Empleado: Nombre, dni, apellido, legajo, dirección, puesto, telefono, jornada, anioIngreso.


class archivoAlumno{
private:
    char _nombre[30];
public:
    //CONSTRUCTOR
    archivoAlumno(const char* nombre="alumnos.dat");

    //METODOS
    bool grabarRegistro(Alumno obj);
    //bool leerRegistro(Alumno obj);
    //int contarRegistros();
    void listar();
};

archivoAlumno::archivoAlumno(const char* nombre){
    strcpy(_nombre,nombre);
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

/*bool archivoAlumno::leerRegistro(Alumno obj){
    FILE *pAlu;
    pAlu=fopen(_nombre,"rb");

    if(pAlu==nullptr){
        //cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    bool leyo=fread(&obj, sizeof obj, 1,pAlu);

    fclose(pAlu);   //CIERRO EL ARCHIVO.

    return leyo;

}*/


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

/*int main(){
    Alumno obj;
    obj.Cargar();

    ///quiero grabar esto en un archivo
    FILE *pAlu;

    pAlu=fopen("alumnos.dat","ab");

    if(pAlu==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }

    fwrite(&obj, sizeof obj, 1,pAlu);

    fclose(pAlu);


	system("pause");
	return 0;

}*/


int main(){
    Alumno obj;


    ///LECTURA DE ARCHIVOS
    FILE *pAlu;
    pAlu=fopen("alumnos.dat","rb");

    if(pAlu==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }

    /*cout<<"Leo repitiendo codigo: "<<endl;
    fread(&obj, sizeof obj, 1,pAlu);
    obj.Mostrar();  //LEE PRIMER REGISTRO

    fread(&obj, sizeof obj, 1,pAlu);
    obj.Mostrar();  //LEE SEGUNDO REGISTRO.

    fread(&obj, sizeof obj, 1,pAlu);
    obj.Mostrar();  //LEE TERCER REGISTRO.*/

    cout<<"leo usando while"<<endl;
    while(fread(&obj, sizeof obj, 1,pAlu)==1){
          obj.Mostrar();
    }


    cout<<endl;
    fclose(pAlu);   //CIERRO EL ARCHIVO.

	system("pause");
	return 0;

}
/*
int main(){

    Alumno objAlumno;
    archivoAlumno regAlumno;

    objAlumno.Cargar();
    if(regAlumno.grabarRegistro(objAlumno)){
        cout<<"todo ok"<<endl;
    }

    regAlumno.listar();


	system("pause");
	return 0;

}*/

//ACTIVIDAD PARA QUE HAGAN USTEDES

///Transformar el fuente actual en un proyecto de Codeblock.
///en el que cada clase tenga un archivo h para su definición (header),
///y en un cpp el desarrollo de los métodos

///Para cada clase desarrollar todos los gets() y los sets()

///Luego hacer un programa con el menú;
///1. Cargar alumnos
///2. Mostrar alumnos
///3. Cargar alumnos dinamico
///4. Mostrar alumnos dinamico (mostrar array dinamico)
///3. Salir del programa

///Desarrollarlo de 2 maneras:
///1. Suponiendo que el curso tiene 10 alumnos
///2. Solicitando al usuario que indique la cantidad de alumnos del curso

///El proyecto puede tener todos los h y cpp que se consideren necesarios

///14/4 ACTIVIDAD - CONTINUACIÓN
/// Cada clase debe tener: 1 cpp y .h
/// Es decir: 1 cpp para alumno, un .h para alumno, un cpp para archivoAlumno, un .h para archivoAlumno, etc.)
///APLICAR ESTE ESQUEMA PARA CADA CLASE!
