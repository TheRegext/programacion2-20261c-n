#include "tareaManager.h"
#include "menu.h"

class TareaMenu: public Menu {
public:
   TareaMenu();
   void mostrarOpciones();
   void ejecutarOpcion(int opcion);
 
private:
   TareaManager _managerTarea;
};


