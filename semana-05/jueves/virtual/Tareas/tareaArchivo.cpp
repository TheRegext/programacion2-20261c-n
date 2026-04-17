#include "tareaArchivo.h"

TareaArchivo::TareaArchivo(std::string nombreArchivo)
:_nombreArchivo(nombreArchivo){
   
}

bool TareaArchivo::guardar(const Tarea &reg){
   FILE *pFile;
   bool result;
   
   pFile = fopen(_nombreArchivo.c_str(), "ab");
   
   if(pFile == nullptr){
      return false;
   }
   
   result = fwrite(&reg, sizeof(Tarea), 1, pFile); 
   
   fclose(pFile);
   
   return result;
}

Tarea TareaArchivo::leer(int pos){
   FILE *pFile;
   Tarea reg;
   
   reg.setId(-1);
   
   pFile = fopen(_nombreArchivo.c_str(), "rb");
   
   if(pFile == nullptr){
      return reg;
   }
   
   fseek(pFile, pos * sizeof(Tarea), SEEK_SET);
   
   fread(&reg, sizeof(Tarea), 1, pFile); 
   
   fclose(pFile);
   
   return reg;
}

int TareaArchivo::getCantidadRegistros(){
   FILE *pFile;
   int cant;

   pFile = fopen(_nombreArchivo.c_str(), "rb");
   
   if(pFile == nullptr){
      return 0;
   }
   
   fseek(pFile, 0, SEEK_END);
   
   cant = ftell(pFile) / sizeof (Tarea);
   
   fclose(pFile);
   
   return cant;
}

int TareaArchivo::getNuevoId(){
   return getCantidadRegistros() + 1;
}





















