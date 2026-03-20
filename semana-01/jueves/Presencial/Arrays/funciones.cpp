#include <iostream>
using namespace std;
#include "funciones.h"

void cargarDatos(bool ventaProductos[20], int productosxSucursal[][20]) {
    int codigoProducto;
    int numeroSucursal;
    int cantidadVendida;

    cout << "Ingrese codigo de producto (0 para finalizar): ";
    cin >> codigoProducto;

    while (codigoProducto != 0) {
        cout << "Ingrese numero de sucursal (1 a 5): ";
        cin >> numeroSucursal;

        cout << "Ingrese cantidad vendida: ";
        cin >> cantidadVendida;

        ventaProductos[codigoProducto-1] = true;
        productosxSucursal[numeroSucursal-1][codigoProducto-1]=cantidadVendida;

        cout << "Ingrese codigo de producto (0 para finalizar): ";
        cin >> codigoProducto;
    }
}

int puntoA(bool productosVendidos[], int cantProductos){
   int cantProductosVendidos = 0;

   for(int i=0; i<cantProductos; i++){
        if(productosVendidos[i] == true){
            cantProductosVendidos++;
        }
   }
   return cantProductos - cantProductosVendidos;
}

void puntoB(int productosxSucursal[][20]){

    for (int i = 0; i < 5; i++){
        cout << "Sucursal " << i + 1 << endl;
        cout << "-------------------------" << endl;

        bool huboVentaEnSucursal = false;
        for (int j = 0; j < 20; j++){
            if (productosxSucursal[i][j] > 0){
                huboVentaEnSucursal = true;
                cout << "Producto " << j+1 << " - Cant: " << productosxSucursal[i][j] << endl;
            }
        }

        if (!huboVentaEnSucursal){
            cout << "No hubo ventas en esta sucursal." << endl << endl;
        }
        else{
            cout << endl;
        }

    }

}

