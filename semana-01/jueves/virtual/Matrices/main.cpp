#include <iostream>
using namespace std;

void puntoA(int cant[5][20])
{
  for(int s=0; s<5; s++)
  {
    cout << "-----------------------" << endl;
    cout << "Sucursal #" << s + 1 << endl;
    for(int p=0; p<20; p++)
    {
      if(cant[s][p] > 0)
      {
        cout << "Producto #" << p + 1 <<": " << cant[s][p] << endl;
      }
    }
  }
}

int main()
{
  int codigoProducto, numeroSucursal, cantidadVendida;

  int cantidades[5][20] = {};

  cout << "Ingrese codigo de producto: ";
  cin >> codigoProducto;

  while(codigoProducto != 0)
  {
    cout << "Ingrese numero de sucursal: ";
    cin >> numeroSucursal;

    cout << "Ingrese cantidad vendida: ";
    cin >> cantidadVendida;

    cantidades[numeroSucursal-1][codigoProducto-1] += cantidadVendida;

    cout << "Ingrese codigo de producto: ";
    cin >> codigoProducto;
  }

  puntoA(cantidades);


  /*
  int vec[5] = {1,2,3,4,5}; /// array unidimensionales

  /// alumnos y notas
  int mat[5][3] =
  {
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {8,8,8},
    {9,9,9},
  }; /// array multidimensionales

  int alumno;
  cout << "Ingrese numero de alumno (1-5): ";
  cin >> alumno;

  for(int c=0; c<3; c++){
    cout << mat[alumno-1][c] << endl;
  }

  */
  /*
  for(int f=0; f<5; f++)
  {
    for(int c=0 ; c<3; c++)
    {
      cout << mat[f][c] << " ";
    }
    cout << endl;
  }
  */
  return 0;
}
