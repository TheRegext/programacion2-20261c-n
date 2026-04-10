///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;

class Circulo{


};


int main(){
    Circulo c1,c2;///c1 y c2 son variables de tipo Circulo
                  ///Como Circulo es una CLASE, c1 yc2 son OBJETOS de la clase Circulo

    c1.cambiarColor(AZUL);///cambiarColor(int ) es un función (método) de la clase Circulo
    c1.cambiarPosicion(50,30);
    c1.cambiarDiametro(50);

    c2.cambiarColor(AMARILLO);
    c2.cambiarPosicion(200,30);
    c2.cambiarDiametro(50);

    c1.Aparecer();
    c2.Aparecer();

    while(c1.posicionX()+50!=c2.posicionX()){
        c1.Mover(10, DERECHA);
        c2.Mover(10,IZQUIERDA);
    }
    c1.Ocultar();
    c2.Ocultar();
	system("pause");
	return 0;

}
