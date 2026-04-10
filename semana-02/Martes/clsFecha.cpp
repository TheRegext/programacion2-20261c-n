///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;

const int ANIOACTUAL=2026;
const int ANIOFIN=2050;

///Clase: es un molde donde se definen las PROPIEDADES y el COMPORTAMIENTO que tendrán
/// los OBJETOS de esa clase
///Propiedades: son las VARIABLES DE LA CLASE
///COMPORTAMIENTO esta definido en los METODOS (FUNCIONES DE LA CLASE)

///Una CLASE tiene diversas partes. Como mínimo tiene que tener una PARTE PRIVADA (private)
/// y otra PUBLICA (public)
///Todo lo que pongamos en la parte privada va a ser accesible SOLO DENTRO DE LA CLASE
///Lo que pongamos en la parte PUBLICA va a ser accesible tanto dentro como fuera.

///ENCAPSULAMIENTO: los datos (propiedades) no puede ser accedidos de manera directa.
///La clase tiene que establecer los mecanismos para el acceso

class Fecha{

    private:
        int dia, mes, anio;

    public:

    //CONSTRUCTOR
    Fecha(int d=0,int m=0, int a=0);

    //METODOS
    void Cargar(){  ///cambiar para usar los sets()
    //void Cargar(int d=0, int m=0, int a=0){  ///cambiar para usar los sets()
        int d, m, a;
        cout<<"DIA ";
        cin>>d;
        setDia(d);
        cout<<"MES ";
        cin>>m;
        setMes(m);
        cout<<"ANIO ";
        cin>>a;
        setAnio(a);

        ///HACER que la fecha sólo se cargue si TODOS los valores son válidos.

       /// Mostrar();dentro de la clase para usar un método se lo llama de manera directa
    }
    void Mostrar();
    ///sets()-> métodos para cambiar el valor de cada propiedad
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
   /// ~Fecha(){ cout<<"SE MURIO EL OBJETO :-("<<endl;}

};
///Funciones globales: no pertenecen a NINGUNA CLASE

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

///tipos de datos registro: contienen un conjunto de valores de igual  o distinto tipo
int main(){
    Fecha hoy, ayer(30);

    hoy.Cargar();
    hoy.Mostrar();

    /*hoy.Mostrar();
    cout<<"OBJETO ayer "<<endl;
    ayer.Mostrar();

    /*hoy.setDia(7);
    if(hoy.getDia()==7){
        cout<<"EL DIA ES 7"<<endl;
    }*/
	system("pause");
	return 0;

}
