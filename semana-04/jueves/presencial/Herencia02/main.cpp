#include <iostream>
using namespace std;

class FiguraGeometrica{

    public:
        virtual float calcularArea(){
            return 0;
        }

};

class Cuadrado : public FiguraGeometrica{
    private:
        float _lado;

    public:
        Cuadrado(float lado){
            _lado = lado;
        }

        float calcularArea(){
            return _lado * _lado;
        }

};

class Circulo : public FiguraGeometrica{
    private:
        float _radio;

    public:
        Circulo(float radio){
            _radio = radio;
        }

        float calcularArea(){
            return 3.14159 * _radio * _radio;
        }
};


void mostrarArea(FiguraGeometrica &figura){
    cout << figura.calcularArea() << endl;
}

class Triangulo:public FiguraGeometrica{
    private:
        float _base, _altura;

    public:
        Triangulo(float base, float altura){
            _base= base;
            _altura=altura;
        }

        float calcularArea(){
            return _base * _altura / 2;
        }
};


int main()
{

    cout << endl;

    Cuadrado cuad(4);
    mostrarArea(cuad);


    cout << endl;

    Circulo circ(3);
    mostrarArea(circ);

    cout << endl;

    Triangulo tri(5, 10);
    mostrarArea(tri);


    return 0;
}
