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
    int getMes(){ return mes;};
    int getAnio(){return anio;}

    void Cargar(){
        cout<<"DIA ";
        cin>>dia;
        cout<<"MES ";
        cin>>mes;
        cout<<"ANIO ";
        cin>>anio;
    }
    void Mostrar();///prototipo del m�todo
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
    bool _estado;///para determinar si el alumno est� o no activo
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

    Fecha getFechaNacimiento(){
        return _fechaNacimiento;
    }

    Fecha getFechaInscripcion(){
        return _fechaInscripcion;
    }
    bool getEstado();
    void Cargar();
    void Mostrar();
    int calcularEdad(Fecha fNac, Fecha fActual);

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
        _fechaInscripcion.Mostrar();
        _fechaInscripcion.MostrarConBarra();
        cout<<"ESTADO: "<<_estado<<endl;
    }
}

int Alumno::calcularEdad(Fecha fNac, Fecha fActual){
    int edad=0;

    edad=fActual.getAnio()-fNac.getAnio();

    if(fActual.getMes()<fNac.getMes()){
        edad=edad-1;
    }

    if(fActual.getMes()==fNac.getMes()){
        if(fActual.getDia()<fNac.getDia()){
            edad=edad-1;
        }
    }

    return edad;
}

///Fin clase Alumno


///Materia: nombre de la materia, horas, c�digo, profesor, idCarrera, codigo, cuatri/anual
///Empleado: Nombre, dni, apellido, legajo, direcci�n, puesto, telefono, jornada, anioIngreso.


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
    void buscarTodosPorEdad(int edad, Fecha fechaActual);
    void buscarTodosPorAnioInscripcion(int a);
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
    //yo encontr� con buscarRegistro() el registro en el 4� registro.
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

///Class Materia
class Materia{
private:
    int _codMateria;
    int _idCarrera;
    char _nombre[20];
    int _horas;
    int _idProfesor;
    bool _cuatrimestral;
    bool _estado;

public:
    //CONSTRUCTOR
    Materia(){
        _codMateria=-1;
        _idCarrera=-1;
        strcpy(_nombre,"vacio");
        _horas=-1;
        _idProfesor=-1;
        _cuatrimestral=-1;
        _estado=0;

    }
    Materia(int materia, int idCarrera, char* nombre, int horas, int idProf, bool cuatri, bool estado){
        _codMateria=materia;
        _idCarrera=idCarrera;
        strcpy(_nombre,nombre);
        _horas=horas;
        _idProfesor=idProf;
        _cuatrimestral=cuatri;
        _estado=estado;
    }

    //METDOS
    int getCodMateria(){return _codMateria;}
    int getIdCarrera(){return _idCarrera;}
    char* getNombre(){return _nombre;}
    int getHoras(){return _horas;}
    int getIdProfesor(){return _idProfesor;}
    bool getEsCuatrimestral(){return _cuatrimestral;}
    bool getEstado(){return _estado;}

    void setCodMateria(int codMat){
        _codMateria=codMat;
    }
    void setIdCarrera(int idCarr){
        _idCarrera=idCarr;
    }
    void setNombreMateria(char* nomMat){
        strcpy(_nombre,nomMat);
    }
    void setHoras(int horas){
        _horas=horas;
    }
    void setIdProfesor(int idProf){
        _idProfesor=idProf;
    }
    void setEsCuatrimestral(bool esCuat){
        _cuatrimestral=esCuat;
    }
    void setEstado(bool estado){
        _estado=estado;
    }

    void Mostrar(){
        cout<<"Cod. Materia: "<<_codMateria<<endl;
        cout<<"Id. Carrera: "<<_idCarrera<<endl;    ///--> AC� VAMOS A VER COMO UNIR ARCHIVOS.
        cout<<"Nombre de la materia: "<<_nombre<<endl;
        cout<<"Horas: "<<_horas<<endl;
        cout<<"Profesor: "<<_idProfesor<<endl;  ///--> AC� VAMOS A VER COMO UNIR ARCHIVOS.
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
    void Cargar(){
        int aux;
        char auxN[20];
        bool auxB;


        cout<<"Id. Carrera: ";
        cin>>aux;
        setIdCarrera(proximoIdPorCarrera(aux));

        cout<<"Cod. Materia: ";
        cin>>aux;
        setCodMateria(aux);

        cout<<"Nombre de la materia: ";
        cin>>auxN;
        setNombreMateria(auxN);

        cout<<"Horas: ";
        cin>>aux;
        setHoras(aux);

        cout<<"Profesor: ";
        cin>>aux;
        setIdProfesor(aux);

        cout<<"Cuatrimestral? (1- SI / 0- NO): ";
        cin>>auxB;
        setEsCuatrimestral(auxB);

        _estado=true;
    }

    int proximoIdPorCarrera(int idCarr){
        archivoMateria arMat;
        return arMat.contarRegistrosPorCarrera(idCarr)+1;
    }

};
class archivoMateria{
private:
    char _nombre[30];
public:
    //CONSTRUCTOR
    archivoMateria(bool vacio=false, const char* nombre="materias.dat");

    //METODOS
    bool grabarRegistro(Materia obj);
    bool bajaLogicaRegistro(int idMateria);
    int buscarMateriaId(int idMateria);
    Materia leerRegistro(int pos);
    bool sobreEscribirRegistro(Materia reg, int pos);
    void listar();
    int contarRegistros();
    int contarRegistrosPorCarrera(int idCarr);
};

archivoMateria::archivoMateria(bool vacio, const char* nombre){
    strcpy(_nombre,nombre);
    if(vacio==true){
      FILE *p=fopen(nombre,"wb");
        fclose(p);
    }
}

bool archivoMateria::grabarRegistro(Materia obj){
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

bool archivoMateria::sobreEscribirRegistro(Materia reg, int pos){
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

int archivoMateria::buscarMateriaId(int idMateria){
    Materia reg;
    int posicion=0;
    FILE *pMat=fopen(_nombre, "rb");

    if(pMat==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return -1;
    }

    while(fread(&reg, sizeof reg, 1, pMat)==1){
        if(idMateria==reg.getCodMateria()){
            fclose(pMat);
            return posicion;
        }
        posicion++;
    }

    fclose(pMat);

    return -1;
}

Materia archivoMateria::leerRegistro(int pos){
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

bool archivoMateria::bajaLogicaRegistro(int codMat){
    Materia reg;

    int pos=buscarMateriaId(codMat);

    if(pos==-1){
        cout<<"LA MATERIA NO EXISTE "<<endl;
        system("pause");
        return false;
    }

    reg=leerRegistro(pos);

    reg.setEstado(false);

    return sobreEscribirRegistro(reg, pos);
}

void archivoMateria::listar(){
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

int archivoMateria::contarRegistros(){
    FILE *p;
    p=fopen(_nombre, "rb");
    if(p==nullptr)return 0;
    fseek(p,0,2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof(Materia);
}

int archivoMateria::contarRegistrosPorCarrera(int idCarr){
    Materia obj;
    int contador=0;
    FILE *pMat;

    pMat=fopen(_nombre,"rb");

    if(pMat==nullptr){
        return;
    }

    while(fread(&obj, sizeof obj, 1,pMat)!=0){
        if(obj.getIdCarrera()==idCarr){
            contador++;
        }
    }

    fclose(pMat);
    return contador;
}




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
        cout<<"5. REPORTES"<<endl;
        cout<<"6. MATERIAS"<<endl;
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
            case 5: menuReportes();
                    break;
            case 6: menuMaterias();
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



///FUNCIONES GLOBALES MATERIA
void altaMateria();
void bajaMateria();
void modificarMateria();
void listarMaterias();

void menuMaterias(){
    int opc;
    while(true){
        system("cls");
        cout<<"******ARCHIVO MATERIAS******"<<endl;
        cout<<"1. ALTA"<<endl;
        cout<<"2. BAJA MATERIA"<<endl;
        cout<<"3. MODIFICAR MATERIA"<<endl;
        cout<<"4. LISTADO COMPLETO"<<endl;
        cout<<"0. VOLVER AL MENU ANTERIOR "<<endl;
        cout<<"***************************"<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: altaMateria();
                    break;
            case 2: bajaMateria();
                    break;
            case 3: modificarMateria();
                    break;
            case 4: listarMaterias();
                    break;
case 0: return;
                    break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    break;

        }
        system("pause");
    }
}


void altaMateria(){
    Materia reg;
    archivoMateria arMat;
    reg.Cargar();
    if(arMat.grabarRegistro(reg)){
        cout<<"SE GRABO EL REGISTRO "<<endl;
    }
    else{
        cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
    }

}
void bajaMateria(){
    Materia reg;
    archivoMateria arMat;
    int codMat;
    cout<<"INGRESAR EL CODIGO DE LA MATERIA A BORRAR ";
    cin>>codMat;
    int pos=arMat.buscarMateriaId(codMat);
    if(pos==-1){
        cout<<"NO HAY MATERIAS CON ESE ID"<<endl;
        return;
    }
    reg=arMat.leerRegistro(pos);
    reg.setEstado(false);
    arMat.sobreEscribirRegistro(reg,pos);

}
void modificarMateria(){
    ///LO DEBEN HACER UDS
}
void listarMaterias(){
    Materia reg;
    archivoMateria arMat;
    int cantReg=arMat.contarRegistros();
    if(cantReg==0){
        cout<<"EL ARCHIVO NO TIENE REGISTROS O NO EXISTE "<<endl;
    }
    else{
            arMat.listar();
    }
}


void menuReportes(){
    int opc;
    while(true){
        system("cls");
        cout<<"******REPORTES DE ALUMNOS******"<<endl;
        cout<<"1. INFORME POR EDAD"<<endl;
        cout<<"2. INFORME POR ANIO DE INSCRIPCIPON"<<endl;
        cout<<"0. VOLVER AL MENU ANTERIOR "<<endl;
        cout<<"***************************"<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: informeEdad();
                    break;
            case 2: informeAnioInscripcion();
                    break;
            case 0: return;
                    break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    break;

        }
        system("pause");
    }
}

void informeEdad(){
    archivoAlumno arAlu;
    int edad;
    Fecha fechaActual;

    cout<<"Ingrese la fecha actual: "<<endl;
    fechaActual.Cargar();

    cout<<"Ingrese la edad de los alumnos a listar: "<<endl;
    cin>>edad;

    arAlu.buscarTodosPorEdad(edad, fechaActual);

}

void informeAnioInscripcion(){
    archivoAlumno arAlu;
    int anio;

    cout<<"Ingrese el anio de inscripcion de los alumnos a buscar: "<<endl;
    cin>>anio;
    cout<<endl<<endl;

    arAlu.buscarTodosPorAnioInscripcion(anio);
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


///clase 5/5/26 - REPORTES
///HACER UN MÉTODO QUE CALCULE EL PRÓXIMO ID A ASIGNAR EN EL ARCHIVO/OBJETO
///HACER UN MÉTODO QUE LISTE SOLAMENTE LOS ALUMNOS DE CIERTA EDAD QUE SE PIDA POR TECLADO
///HACER UN MÉTODO QUE LISTE SOLAMENTE LOS ALUMNOS DE CIERTO AÑO DE INSCRIPCIÓN QUE SE INDIQUE POR TECLADO.
