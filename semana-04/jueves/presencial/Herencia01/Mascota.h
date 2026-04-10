#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

#include <string>
#include "Animal.h"

class Mascota : public Animal{
    private:
        std::string _nombre;
        std::string _nombreDuenio;

    public:
        Mascota(std::string especie, float peso, std::string nombre, std::string nombreDuenio);
        void irAlVeterinario();
        std::string getNombre();
        std::string getNombreDuenio();
        void setNombre(std::string nombre);
        void setNombreDuenio(std::string nombreDuenio);
};


#endif // MASCOTA_H_INCLUDED
