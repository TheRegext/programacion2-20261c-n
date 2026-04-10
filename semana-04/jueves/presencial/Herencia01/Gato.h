#ifndef GATO_H_INCLUDED
#define GATO_H_INCLUDED

#include "Mascota.h"

class Gato:public Mascota{
    private:
        bool _esDeInterior;

    public:
        Gato(float peso, string nombre, string nombreDuenio, bool esDeInterior);
        void maullar();

};

#endif // GATO_H_INCLUDED
