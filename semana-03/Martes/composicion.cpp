# include<iostream>
# include<cstring>

using namespace std;

const int ANIOACTUAL=2026;
const int ANIOFIN=2050;

///COMPOSICION: es un mecanismo mediante el cual usamos como propiedad de una clase un OBJETO de otra clase
///Un objeto puede ser parte de otra clase, pero esa clase no va a poder acceder de manera directa sus propiedades.
///Necesita usar los métodos de la clase a la que pertenece

///Se usa cuando una clase TIENE como propiedad un OBJETO de otra

///NOTA: ÚLTIMA SEMANA PARA DEFINIR GRUPOS!

///clase Fecha
class Fecha{

    private:
        int dia, mes, anio;

    public:

    //CONSTRUCTOR
    Fecha(int d=0,int m=0, int a=0);

    //METODOS
    bool validarFecha(int d, int m, int a);
    void Cargar();
    void Mostrar();


    ///sets()-> metodos para cambiar el valor de cada propiedad
    ///validar los valores recibidos para cada propiedad


    //SETTERS Y GETTERS
    void setDia(int d){
        if(d>=1 && d<=31) {
            dia=d;
        }
        else{
            dia=0;
        }
    }
    void setMes(int m){
        if(m>0 && m<=12){
                mes=m;
        }
        else{
            m=0;
        }
    }
    void setAnio(int a){
        if(a>=ANIOACTUAL && a<=ANIOFIN){
                anio=a;
        }
    }
    ///
    ///gets()->
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    //~Fecha(){ cout<<"SE MURIO EL OBJETO :-("<<endl;}    //DESTRUCTOR

};
///Funciones globales: no pertenecen a NINGUNA CLASE


///HACER que la fecha solo se cargue si TODOS los valores son validos.
bool Fecha::validarFecha(int d, int m, int a){
    //30 días: Abril, Junio, Septiembre y Noviembre
    //28 días: Febrero (pueden desarrollar uds un método bisiesto)
    //31 días: Los demás
    //12 meses

    if ((a<ANIOACTUAL || a>ANIOFIN) || (m<1 || m>12) || (d<1 || d>31)){
        return false;
    }

    if(m==4 || m==6 || m==9 || m==11){
        if(d<1 || d>30){
            return false;
        }
    }

    if(m==2){
        if(d<1 || d>28){
            return false;
        }
    }

    return true;
}

void Fecha::Cargar(){  ///cambiar para usar los sets()
    //void Cargar(int d=0, int m=0, int a=0){  ///cambiar para usar los sets()
    int d, m, a;
    cout<<"DIA ";
    cin>>d;
    cout<<"MES ";
    cin>>m;
    cout<<"ANIO ";
    cin>>a;

    while(!validarFecha(d, m, a)){
        cout<<"Fecha ingresada invalida, por favor ingrese nuevamente la fecha: "<<endl;
        cout<<"DIA ";
        cin>>d;
        cout<<"MES ";
        cin>>m;
        cout<<"ANIO ";
        cin>>a;
   }

    setDia(d);
    setMes(m);
    setAnio(a);


   /// Mostrar();dentro de la clase para usar un metodo se lo llama de manera directa
}

void Fecha::Mostrar(){
        cout<<"DIA "<<dia<<endl;
        cout<<"MES "<<mes<<endl;
        cout<<"ANIO "<<anio<<endl;
}

Fecha::Fecha(int d,int m, int a){
    dia=d;
    mes=m;
    anio=a;
}
///Fin clase Fecha


///Clase Alumno
class Alumno{
    private:///propiedades
        char nombre[30], apellido[30];
        int legajo;
        Fecha fechaInscripcion; //composición
        Fecha fechaNacimiento;  //composición

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
    fechaNacimiento.Mostrar();
    cout<<"FECHA DE INSCRIPCION ";
    fechaInscripcion.Mostrar();
}
///Fin clase Alumno

void Cargar(){

    ///
}

int main(){
    Fecha hoy;
    cout<<"OBJETO HOY "<<endl;
    hoy.Cargar();
    hoy.Mostrar();
    cout<<endl;

    Alumno al;
    al.Cargar();
    al.Mostrar();

	system("pause");
	return 0;
}


//ACTIVIDAD PARA QUE HAGAN USTEDES

///Transformar el fuente actual en un proyecto de Codeblock
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
