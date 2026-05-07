#include <iostream>
#include "Alumnos.h"
#include "ArchivoAlumnos.h"
#include "Materias.h"
#include "ArchivoMaterias.h"
#include "Docentes.h"
#include "ArchivoDocentes.h"

using namespace std;


///clase 5/5/26 - REPORTES
///HACER UN MÉTODO QUE CALCULE EL PRÓXIMO ID A ASIGNAR EN EL ARCHIVO/OBJETO
///HACER UN MÉTODO QUE LISTE SOLAMENTE LOS ALUMNOS DE CIERTA EDAD QUE SE PIDA POR TECLADO
///HACER UN MÉTODO QUE LISTE SOLAMENTE LOS ALUMNOS DE CIERTO AÑO DE INSCRIPCIÓN QUE SE INDIQUE POR TECLADO.
///LUEGO DEL RECREO
///HACER UN MÉTODO QUE LISTE A LOS DOCENTES DE LA CARRERA 3
///HACER UN MÉTODO QUE LISTE LAS MATERIAS DE LA CARRERA 2
///HACER UN MÉTODO QUE LISTE A LOS DOCENTES CON ANTIGUEDAD MAYOR A 10 AÑOS
///CREAR LA CLASE INSCRIPCIONES CON SU ARCHIVOINSCRIPCIONES DONDE FIGURE LEGAJO ALUMNO, IDCARRERA, CODMATERIA, FECHA
///HACER UNA CLASE DONDE FIGURE EL ANALÍTICO DEL ALUMNO Y QUE INDIQUE LEGAJO ALUMNO, IDCARRERA, CODMATERIA, NOTA FINAL, FECHA
///HACER UN MÉTODO QUE LISTE LAS MATERIAS APROBADAS DEL LEGAJO DEL ALUMNO QUE SE PIDA POR TECLADO

///funciones globales
void altaRegistro();
void bajaRegistro();
void modificarNombre();
void modificarApellido();
void listadoCompleto();
void menuReportes();
void menuMaterias();
void informeEdad();
void informeAnioInscripcion();
void menuModificacion();
void menuDocentes();
void informeDocentesCarrera3();
void informeMateriasCarrera();
void informeDocentesAntiguedad();
///

int main()
{
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
        cout<<"7. DOCENTES"<<endl;
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
            case 7: menuDocentes();
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
    ArchivoMateria arMat;
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
    ArchivoMateria arMat;
    int idCarr, codMat;

    cout<<"INGRESAR EL CODIGO DE LA CARRERA ";
    cin>>idCarr;

    cout<<"INGRESAR EL CODIGO DE LA MATERIA A BORRAR ";
    cin>>codMat;
    int pos=arMat.buscarMateriaId(idCarr, codMat);
    if(pos==-1){
        cout<<"NO HAY MATERIAS CON ESE ID"<<endl;
        return;
    }
    reg=arMat.leerRegistro(pos);
    reg.setEstado(false);
    arMat.sobreEscribirRegistro(reg,pos);

}
void modificarMateria(){
    Materia reg;
    ArchivoMateria arMat;
    int codMat, idCarr;

    cout<<"INGRESAR CODIGO DE LA CARRERA ";
    cin>>idCarr;

    cout<<"INGRESAR CODIGO DE LA MATERIA A MODIFICAR ";
    cin>>codMat;
    int pos=arMat.buscarMateriaId(idCarr, codMat);

    if(pos==-1){
        cout<<"NO HAY MATERIAS CON ESE CODIGO EN ESA CARRERA"<<endl;
        return;
    }

    cout<<"INGRESE EL NUEVO LEGAJO DEL DOCENTE ";
    int nuevoLegajo;
    cin>>nuevoLegajo;

    reg=arMat.leerRegistro(pos);
    reg.setLegajoDocente(nuevoLegajo);
    arMat.sobreEscribirRegistro(reg,pos);

}
void listarMaterias(){
    Materia reg;
    ArchivoMateria arMat;
    int cantReg=arMat.contarRegistros();
    if(cantReg==0){
        cout<<"EL ARCHIVO NO TIENE REGISTROS O NO EXISTE "<<endl;
    }
    else{
            arMat.listar();
    }
}

///HACER UN MÉTODO QUE LISTE A LOS DOCENTES DE LA CARRERA 3

void menuReportes(){
    int opc;
    while(true){
        system("cls");
        cout<<"******REPORTES VARIOS******"<<endl;
        cout<<"1. INFORME POR EDAD"<<endl;
        cout<<"2. INFORME POR ANIO DE INSCRIPCIPON"<<endl;
        cout<<"3. LISTAR DOCENTES DE LA CARRERA NRO 3"<<endl;
        cout<<"4. LISTAR MATERIAS DE UNA CARRERA"<<endl;
        cout<<"5. LISTAR DOCENTES CON ANTIGUEDAD MAYOR A 10 AÑOS"<<endl;
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
            case 3: informeDocentesCarrera3();
                    break;
            case 4: informeMateriasCarrera();
                    break;
            case 5: informeDocentesAntiguedad();
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

void informeDocentesCarrera3(){
    ArchivoDocente arDoc;
    Materia mat;
    ArchivoMateria arMat;

    int idCarrera=3;

    arDoc.listarDocentesCarrera3(idCarrera);

    //1° recorro uno a uno los registros de docente
    //una vez que leo el primero, tomo el legajo y busco en archivo materias que coincida el legajo
    //y el código de carrera

}

void informeMateriasCarrera(){
    Materia mat;
    ArchivoMateria arMat;
    int codCarrera;

    cout<<"Ingrese el codigo de carrera para listar las materias: ";
    cin>>codCarrera;

    arMat.listarMateriasCarrera(codCarrera);
}


void informeDocentesAntiguedad(){
    ///INFORMAR DOCENTES CON ANTIGUEDAD MAYOR A 10 AÑOS
    Docente doc;
    ArchivoDocente arDoc;

    int antig=10;

    arDoc.listarDocentesAntiguedad(antig);

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


///FUNCIONES GLOBALES DOCENTE
void altaDocente();
void bajaDocente();
void modificarDocente();
void listarDocentes();


void menuDocentes(){
    int opc;
    while(true){
        system("cls");
        cout<<"******ARCHIVO DOCENTES******"<<endl;
        cout<<"1. ALTA"<<endl;
        cout<<"2. BAJA DOCENTE"<<endl;
        cout<<"3. MODIFICAR DOCENTE"<<endl;
        cout<<"4. LISTADO COMPLETO"<<endl;
        cout<<"0. VOLVER AL MENU ANTERIOR "<<endl;
        cout<<"***************************"<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: altaDocente();
                    break;
            case 2: bajaDocente();
                    break;
            case 3: modificarDocente();
                    break;
            case 4: listarDocentes();
                    break;
            case 0: return;
                    break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    break;

        }
        system("pause");
    }
}

void altaDocente(){
    Docente reg;
    ArchivoDocente arDoc;
    reg.Cargar();
    if(arDoc.grabarRegistro(reg)){
        cout<<"SE GRABO EL REGISTRO "<<endl;
    }
    else{
        cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
    }

}
void bajaDocente(){
    Docente reg;
    ArchivoDocente arDoc;
    int legajo;
    cout<<"INGRESAR EL LEGAJO DEL DOCENTE A BORRAR ";
    cin>>legajo;
    int pos=arDoc.buscarLegajo(legajo);
    if(pos==-1){
        cout<<"NO HAY MATERIAS CON ESE ID"<<endl;
        return;
    }
    reg=arDoc.leerRegistro(pos);
    reg.setEstado(false);
    arDoc.sobreEscribirRegistro(reg,pos);

}
void modificarDocente(){
    ///LO DEBEN HACER UDS
}
void listarDocentes(){
    ArchivoDocente arDoc;
    int cantReg=arDoc.contarRegistros();
    if(cantReg==0){
        cout<<"EL ARCHIVO NO TIENE REGISTROS O NO EXISTE "<<endl;
    }
    else{
            arDoc.listar();
    }
}
