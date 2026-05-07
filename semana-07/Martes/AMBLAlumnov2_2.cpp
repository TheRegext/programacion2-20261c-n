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
    bool _estado;///para determinar si el alumno está o no activo
public:

    void setLegajo(int legajo);
    int getLegajo();
    void setEstado(bool estado);
    void setNombre(const char* nombre){
        strcpy(_nombre, nombre);
    }

    void setApellido(const char* nombre){
        strcpy(_apellido, nombre);
    }
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
    if(_estado==true){
        cout<<_nombre<<" "<<_apellido<<endl;
        cout<<"LEGAJO "<<_legajo<<endl;
        cout<<"FECHA DE NACIMIENTO ";
        _fechaNacimiento.MostrarConBarra();
        cout<<"FECHA DE INSCRIPCION ";
        _fechaInscripcion.MostrarConBarra();
        cout<<"ESTADO: "<<_estado<<endl;
    }
}


///Fin clase Alumno

///Materia: nombre de la materia, horas, código, profesor, idCarrera, codigo, cuatri/anual
///Empleado: Nombre, dni, apellido, legajo, dirección, puesto, telefono, jornada, anioIngreso.


class archivoAlumno{
private:
    char _nombre[30];
public:
    //CONSTRUCTOR
    archivoAlumno(bool vacio=false, const char* nombre="alumnos.dat");

    //METODOS
    bool grabarRegistro(Alumno obj);
    bool bajaLogicaRegistro(int legajo);
    int buscarLegajo(int legajo);
    Alumno leerRegistro(int pos);
    bool sobreEscribirRegistro(Alumno reg, int pos);
    void listarActivos();
    void listar();
    int contarRegistros();
};

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


///funciones globales
void altaRegistro();
void bajaRegistro();
void modificarNombre();
void modificarApellido();
void listadoCompleto();
void menuModificacion();
///

int main(){
   /// archivoAlumno arAlu(true,"alumnos.dat");
    int opc;
    while(true){
        system("cls");
        cout<<"******ARCHIVO ALUMNOS******"<<endl;
        cout<<"1. ALTA"<<endl;
        cout<<"2. BAJA LOGICA"<<endl;
        cout<<"3. MODIFICAR REGISTRO"<<endl;
        cout<<"4. LISTADO COMPLETO"<<endl;
        cout<<"0. FIN DEL PROGRAMA"<<endl;
        cout<<"***************************"<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: altaRegistro();
                    break;
            case 2: bajaRegistro();
                    break;
            case 3: menuModificacion();
                    break;
            case 4: listadoCompleto();
                    break;
            case 0: return 0;
                    break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    break;

        }
        system("pause");
    }

    return 0;
}

void altaRegistro(){
    Alumno reg;
    archivoAlumno arAlu;
    reg.Cargar();
    if(arAlu.grabarRegistro(reg)){
        cout<<"SE GRABO EL REGISTRO "<<endl;
    }
    else{
        cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
    }
}

void bajaRegistro(){
    Alumno reg;
    archivoAlumno arAlu;
    int legajo;
    cout<<"INGRESAR LEGAJO DEL ALUMNO A BORRAR ";
    cin>>legajo;
    int pos=arAlu.buscarLegajo(legajo);
    if(pos==-1){
        cout<<"NO HAY ALUMNOS CON ESE LEGAJO"<<endl;
        return;
    }
    reg=arAlu.leerRegistro(pos);
    reg.setEstado(false);
    arAlu.sobreEscribirRegistro(reg,pos);
}


void menuModificacion(){
    int opc;
    while(true){
        system("cls");
        cout<<"******MODIFICACION ALUMNOS******"<<endl;
        cout<<"1. MODIFICAR NOMBRE "<<endl;
        cout<<"2. MODIFICAR APELLIDO"<<endl;
        cout<<"0. VOLVER AL MENU ANTERIOR "<<endl;
        cout<<"***************************"<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: modificarNombre();
                    break;
            case 2: modificarApellido();
                    break;
            case 0: return;
                    break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    break;

        }
        system("pause");
    }
}

void modificarNombre(){
    Alumno reg;
    archivoAlumno arAlu;
    int legajo;
    cout<<"INGRESAR LEGAJO DEL ALUMNO A MODIFICAR ";
    cin>>legajo;
    int pos=arAlu.buscarLegajo(legajo);
    if(pos==-1){
        cout<<"NO HAY ALUMNOS CON ESE LEGAJO"<<endl;
        return;
    }
    cout<<"INGRESE EL NUEVO NOMBRE ";
    char nombre[30];
    cin>>nombre;

    reg=arAlu.leerRegistro(pos);
    reg.setNombre(nombre);
    arAlu.sobreEscribirRegistro(reg,pos);
}

void modificarApellido(){
    Alumno reg;
    archivoAlumno arAlu;
    int legajo;
    cout<<"INGRESAR LEGAJO DEL ALUMNO A MODIFICAR ";
    cin>>legajo;
    int pos=arAlu.buscarLegajo(legajo);
    if(pos==-1){
        cout<<"NO HAY ALUMNOS CON ESE LEGAJO"<<endl;
        return;
    }
    cout<<"INGRESE EL NUEVO APELLIDO ";
    char nombre[30];
    cin>>nombre;

    reg=arAlu.leerRegistro(pos);
    reg.setApellido(nombre);
    arAlu.sobreEscribirRegistro(reg,pos);
}


void listadoCompleto(){
    Alumno reg;
    archivoAlumno arAlu;
    int cantReg=arAlu.contarRegistros();
    if(cantReg==0){
        cout<<"EL ARCHIVO NO TIENE REGISTROS O NO EXISTE "<<endl;
    }
    else    arAlu.listarActivos();
}
