#include <iostream>
using namespace std;
#include "Animal.h"
#include "Mascota.h"
#include "Gato.h"

int main()
{
    Animal a("Ballena", 999);

    a.mostrarInfoBiologica();
    a.comer();

    cout << endl << endl;

    Mascota m("Canino", 4, "Rocky", "Angel");
    m.mostrarInfoBiologica();
    m.comer();
    m.irAlVeterinario();

    cout << endl << endl;

    Gato g(5.5, "Pancito", "Angel", 1);
    g.mostrarInfoBiologica();
    g.comer();
    g.irAlVeterinario();
    g.maullar();

    return 0;
}
