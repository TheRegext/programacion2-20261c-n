#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include<string>

class Animal{
    private:
        std::string _especie;
        float _peso;

    public:
        Animal(std::string especie, float peso);
        void comer();
        void mostrarInfoBiologica();
        void setEspecie(std::string especie);
        void setPeso(float peso);
        float getPeso();

};

#endif // ANIMAL_H_INCLUDED
