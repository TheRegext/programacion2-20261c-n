#include <iostream>
#include "Examen.h"
#include "AgenteArchivo.h"
#include "MultaArchivo.h"

using namespace std;

/**
Listar la cantidad de agentes distintos que hayan realizado al menos una multa 
con un monto individual de más de $25000 y que se encuentre pagada.
*/

void Examen::Punto1() {
  AgenteArchivo repoAgente;
  MultaArchivo repoMulta;
  int cantidadAgentes = repoAgente.getCantidadRegistros();
  int cantidadMultas = repoMulta.getCantidadRegistros();
  int cantidad = 0;
  
  for(int i=0; i<cantidadAgentes; i++){
    Agente agente = repoAgente.leer(i);
    bool tieneMultas = false;
      
    for(int j=0; j<cantidadMultas; j++){
      Multa multa = repoMulta.leer(j);
      
      if(multa.getIDAgente() == agente.getIdAgente()
         && multa.getMonto() > 25000
         && multa.getPagada() == true
         && multa.getEliminado() == false
         ){
        tieneMultas = true;
      }
    }
    
    if(tieneMultas){
      cantidad++;
    }
  }
  
  cout << "La cantidad de agentes con multas son: " << cantidad << endl;
  
	
}

/**
A partir de un año que se recibe por parámetro 
listar el o los tipos de infracciónes que más multas haya registrado en ese año.

NOTA: Son 40 tipos de infracciones. Los valores de tipo de infracción están 
comprendidos entre 1 y 40.
*/

void Examen::Punto2(int anio) {
  int cantidad[40]={0};
  MultaArchivo repoMulta;
  int cantidadMultas = repoMulta.getCantidadRegistros();
  
  for(int j=0; j<cantidadMultas; j++){
    Multa multa = repoMulta.leer(j);
    
    if(multa.getEliminado() == false && multa.getFechaMulta().getAnio() == anio){
      cantidad[multa.getTipoInfraccion() - 1]++;
    }
  }
  
  int maxInf = 0;
  
  for(int i=0; i< 40; i++){
    if(cantidad[i] > cantidad[maxInf]){
      maxInf = i;
    }
  }
  
  ///cout << "El tipo con mayor infraccion en " << anio << " es: " << maxInf+1<<endl;
  cout << "Los tipos con mayor infraccion en " << anio << " son: " << endl;
  
  for(int i=0; i< 40; i++){
    if(cantidad[i] == cantidad[maxInf]){
      cout << "Tipo: " << i + 1 << endl;
    }
  }
}

/**
  Crear un archivo llamado "AgentesSinMultas.dat" con los agentes 
  que no hayan hecho multas en la localidad 5. 
  El archivo debe registrar todos los atributos de Agente.
*/

void Examen::Punto3() {
  AgenteArchivo repoAgenteSinMulta("AgentesSinMultas.dat");
  repoAgenteSinMulta.vaciar();
  
  AgenteArchivo repoAgente;
  MultaArchivo repoMulta;
  int cantidadAgentes = repoAgente.getCantidadRegistros();
  int cantidadMultas = repoMulta.getCantidadRegistros();
  
  for(int i=0; i<cantidadAgentes; i++){
    Agente agente = repoAgente.leer(i);
    bool tieneMulta5 = false;
    
    for(int j=0; j<cantidadMultas; j++){
      Multa multa = repoMulta.leer(j);
      
      if(multa.getIDAgente() == agente.getIdAgente()
         && multa.getIDLocalidad() == 5
         && multa.getEliminado() == false
         ){
        tieneMulta5 = true;
      }
    }
    
    if(!tieneMulta5){
      repoAgenteSinMulta.guardar(agente);
    }
  }
}
