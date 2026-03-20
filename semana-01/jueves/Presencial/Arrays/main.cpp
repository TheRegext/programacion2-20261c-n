/**
Una cadena de materiales de construcción tiene 5 sucursales y vende
20 productos diferentes. Se desea procesar el movimiento de stock del
día.
Datos de entrada: El sistema recibe registros de ventas sin un orden
particular:
1. Código de Producto (1 a 20).
2. Número de Sucursal (1 a 5).
3. Cantidad vendida (un número entero).
La carga de datos finaliza cuando se ingresa un Código de Producto
igual a 0.
Se pide informar:

A) La cantidad de productos que no se vendieron nunca.
B) Por cada sucursal, los códigos de productos vendidos y su cantidad.}

Sucursal 1
-----------
Producto 1 - Cant: 10
Producto 5 - Cant: 40


Sucursal 2
-----------
Producto 1 - Cant: 10
Producto 5 - Cant: 40


*/

#include <iostream>
using namespace std;
#include "funciones.h"

int main()
{
    bool ventaProductos[20]={};
    int productosxSucursal[5][20]={};

    cargarDatos(ventaProductos, productosxSucursal);
    int cantProductosNoVendidos = puntoA(ventaProductos, 20);
    cout << "A): " << cantProductosNoVendidos << endl;

    puntoB(productosxSucursal);

    return 0;
}
