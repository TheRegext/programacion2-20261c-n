///Fecha:
///Autor:
///Comentario:

#include <iostream>

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
    bool estado;///si el valor es true el registro está activo; y si es false el registro está borrado
public:
    void Cargar();
    void Mostrar();
    void setEstado(bool e){estado=e;}
    int getLegajo(){return legajo;}
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
    estado=true;
}

void Alumno::Mostrar(){
    if(estado==true){
        cout<<nombre<<" "<<apellido<<endl;
        cout<<"LEGAJO "<<legajo<<endl;
        cout<<"FECHA DE NACIMIENTO ";
        fechaNacimiento.MostrarConBarra();
        cout<<"FECHA DE INSCRIPCION ";
        fechaInscripcion.MostrarConBarra();
    }
}

///Fin clase Alumno
///prototipo de funciones
void agregarRegistro();
void bajaLogicaRegistro();
void listarRegistros();
int buscarLegajo(int legajo);
Alumno leerRegistro(int pos);
void sobreEscribirRegistro(Alumno reg, int pos);


int main(){
    int opc;
    while(true){
        system("cls");
        cout<<"---------------- "<<endl;
        cout<<"1. ALTA "<<endl;
        cout<<"2. BAJA LOGICA "<<endl;
        cout<<"3. LISTADO "<<endl;
        cout<<"0. SALIR "<<endl;
        cout<<"---------------- "<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: agregarRegistro();
                    break;
            case 2: bajaLogicaRegistro();
                    break;
            case 3: listarRegistros();
                    break;
            case 0: return 0;
                    break;


        }
        system("pause");


    }
   	system("pause");
	return 0;

}

///Desarollo de las funciones

void agregarRegistro(){
    Alumno reg;
    reg.Cargar();
    FILE *pAlu=fopen("alumnos.dat", "ab");
    if(pAlu==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return;
    }
    fwrite(&reg, sizeof reg, 1, pAlu);
    fclose(pAlu);
}

void bajaLogicaRegistro(){
    Alumno reg;
    int legajo;
    cout<<"INGRESAR LEGAJO DEL ALUMNO A BORRAR ";
    cin>>legajo;
    int pos=buscarLegajo(legajo);
    if(pos==-1){
        cout<<"EL LEGAJO NO EXISTE "<<endl;
        system("pause");
        return;
    }
    reg=leerRegistro(pos);
    reg.setEstado(false);
    sobreEscribirRegistro(reg, pos);

}

void listarRegistros(){
    Alumno reg;
    FILE *pAlu=fopen("alumnos.dat", "rb");
    if(pAlu==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return;
    }

    while(fread(&reg, sizeof reg, 1, pAlu)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(pAlu);

}

int buscarLegajo(int legajo){
    Alumno reg;
    FILE *pAlu=fopen("alumnos.dat", "rb");
    if(pAlu==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return -1;
    }
    int posicion=0;

    while(fread(&reg, sizeof reg, 1, pAlu)==1){
        if(legajo==reg.getLegajo())
            return posicion;
        posicion++;
    }
    fclose(pAlu);
    return -1;
}

Alumno leerRegistro(int pos){
    Alumno reg;
    FILE *pAlu=fopen("alumnos.dat", "rb");
    if(pAlu==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return reg;
    }
    fseek(pAlu,pos*sizeof reg,0); ///SEEK_SET->0 PRINCIPIO; SEEK_CUR->1 POSICION ACTUAL; SEEK_END->2 FINAL DEL ARCHIVO

    fread(&reg, sizeof reg, 1, pAlu);
    fclose(pAlu);
    return reg;
}

void sobreEscribirRegistro(Alumno reg, int pos){
    FILE *pAlu=fopen("alumnos.dat", "rb+");///+ le agrega al modo lo que le falta
    if(pAlu==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return;
    }
    fseek(pAlu,pos*sizeof reg,0); ///SEEK_SET->0 PRINCIPIO; SEEK_CUR->1 POSICION ACTUAL; SEEK_END->2 FINAL DEL ARCHIVO

    fwrite(&reg, sizeof reg, 1, pAlu);
    fclose(pAlu);
}
