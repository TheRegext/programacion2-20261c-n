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
    char _nombre[30], _apellido[30];
    int _legajo;
    Fecha _fechaInscripcion;
    Fecha _fechaNacimiento;
    bool _estado;
public:

    void setLegajo(int legajo);
    int getLegajo();
    void setEstado(bool estado);
    bool getEstado();
    void Cargar();
    void Mostrar();
};


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
    cout<<_nombre<<" "<<_apellido<<endl;
    cout<<"LEGAJO "<<_legajo<<endl;
    cout<<"FECHA DE NACIMIENTO ";
    _fechaNacimiento.MostrarConBarra();
    cout<<"FECHA DE INSCRIPCION ";
    _fechaInscripcion.MostrarConBarra();
    cout<<"ESTADO: "<<_estado<<endl;
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
    bool bajaLogicaRegistro(int legajo);
    int buscarLegajo(int legajo);
    Alumno leerRegistro(int pos);
    bool sobreEscribirRegistro(Alumno reg, int pos);
    void listarActivos();
    void listar();
    //int contarRegistros();
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

bool archivoAlumno::sobreEscribirRegistro(Alumno reg, int pos){
    FILE *pAlu=fopen(_nombre, "rb+");///+ le agrega al modo lo que le falta

    if(pAlu==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return false;
    }

    ///archivo --> 8 bytes: puntero va a quedar en el byte 8. (posicion 0)
    ///archivo --> 8 bytes: puntero va a quedar en el byte 16 (posicion 1)
    //cada registro pesa 8 bytes.
    //yo encontré con buscarRegistro() el registro en el 4° registro.
    //8 x 4 = 32 bytes

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



int main(){
    Alumno obj;
    archivoAlumno reg;
    int pos2;

//    for(int i=0; i<3; i++){
//        obj.Cargar();
//        reg.grabarRegistro(obj);
//    }
//
    cout<<"Listado completo: "<<endl<<endl;
    reg.listar();

    cout<<"Listado sólo de activos: "<<endl;
    reg.listarActivos();


    system("pause");
    return 0;

    cout<<"busco un legajo en particular: "<<endl;
    pos2=reg.buscarLegajo(9999);

    if(pos2>=0){
        obj=reg.leerRegistro(pos2);
        cout<<"Muestro el registro leido: "<<endl;
        obj.Mostrar();
        if(reg.bajaLogicaRegistro(obj.getLegajo())){
            cout<<"Baja exitosa!"<<endl;
            cout<<"Mostrando registro dado de baja: "<<endl;
            //cout<<obj.getEstado()<<endl;
            obj=reg.leerRegistro(pos2);
            obj.Mostrar();
        }
        else{
            cout<<"No se pudo dar de baja"<<endl;
        }
    }
    else{
        cout<<"el legajo no existe"<<endl;
    }

    //ejercicio: dar de alta a Ailin, actualizar el archivo.
    //1° buscamos
    cout<<"Indique el alumno a dar de alta o reactivar: "<<endl;
    int legaAux;
    cin>>legaAux;
    pos2=reg.buscarLegajo(legaAux);

    if(pos2>=0){
        //leemos el registro en base a la posición encontrada
        obj=reg.leerRegistro(pos2);
        //seteamos el estado en true para reactivar.
        obj.setEstado(true);
        if(reg.sobreEscribirRegistro(obj,pos2)){
            cout<<endl<<"Registro reactivado!"<<endl<<endl;
        }
        else{
            cout<<"No se pudo modificar"<<endl;
        }

    }
    else{
    cout<<"el legajo no existe"<<endl;
}







    return 0;

    //BUSCO EL REGISTRO POR LEGAJO
    int pos=reg.buscarLegajo(5555);

    //AL OBJETO Alumno LE ASIGNO LO QUE RETORNA LA FUNCIÓN, QUE ES UN OBJETO Alumno, LUEGO MUESTRO POR PANTALLA
    obj=reg.leerRegistro(pos);
    cout<<"Muestro el objeto grabado en disco: "<<endl;
    obj.Mostrar();




    //obj.Cargar();
    //obj.setEstado(true);

        obj.setLegajo(1234);
        obj.setEstado(true);
    if(reg.sobreEscribirRegistro(obj, pos)){
        cout<<endl<<"Modificacion correcta"<<endl;
    }

    obj=reg.leerRegistro(pos);
    cout<<endl<<"Registro modificado que leimos del archivo: "<<endl;
    obj.Mostrar();

    cout<<endl<<"Listado completo: "<<endl;
    reg.listar();


    return 0;

    //ACÁ YA TENGO LEIDO EL REGISTRO, ASÍ QUE LO TRAJE A MEMORIA. LE MODIFICO EL VALOR DEL ESTADO PARA HACER LA BAJA LÓGICA
    cout<<"doy de baja un registro:"<<endl;
    if(reg.bajaLogicaRegistro(obj.getLegajo())){
        cout<<"Baja dada correctamente"<<endl;
    }
    else{
        cout<<"Error en baja"<<endl<<endl;
    }


    reg.listar();

    return 0;
    obj.setLegajo(8888);
    //NO BASTA CON CAMBIAR EL ESTADO EN MEMORIA, HAY QUE GUARDAR LOS CAMBIOS EN DISCO. POR ESO SOBREESCRIBO EL REGISTRO.
    cout<<"sobreescribo registro despues de modificar el legajo"<<endl;
    if(reg.sobreEscribirRegistro(obj, pos)){
        cout<<"Modificacion correcta"<<endl;
    }

    //LISTO TODO EL ARCHIVO
    cout<<"Listado completo: "<<endl;
    reg.listar();

    //ACÁ VUELVO A BUSCARLO, A LEERLO, Y EFECTIVAMENTE VEO QUE EL ESTADO PASÓ A FALSE.
    cout<<"Muestro el registro modificado, leido desde el archivo"<<endl;
    pos=reg.buscarLegajo(1234);
    obj=reg.leerRegistro(pos);
    obj.Mostrar();

    return 0;


    if(reg.grabarRegistro(obj)){
        cout<<"Registro agregado correctamente"<<endl;
    }


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

/// 21/4: ACTIVIDAD - CONTINUACIÓN
///IMPLEMENTAR MÉTODOS QUE TENGAN PARÁMETROS POR OMISIÓN PARA LISTAR ACTIVOS, INACTIVOS Y TODOS.
/// IMPLEMENTAR UN MÉTODO DE ALTA LÓGICA

