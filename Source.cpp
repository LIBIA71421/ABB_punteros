#include "ArbolRN.h"
#include <fstream>

void leerDeArchivo(ArbolRN<int>& arbolBinario)
{
    ifstream archi;
    int numerosArchivo;


    archi.open("10000_Numeros.txt");

    if (!archi)
        cout << "No se puede abrir";
    else
        while (!archi.eof() && archi >> numerosArchivo)
        {
            arbolBinario.Insertar(numerosArchivo);
        }
    archi.close();
}

int main()
{
    ArbolRN<int> arbol;
    arbol.Insertar(7);
    arbol.Insertar(15);
    arbol.Insertar(8);
    arbol.Insertar(12);
    arbol.Insertar(9);
    arbol.Insertar(5);
    arbol.Insertar(3);
    arbol.Insertar(2);
    // arbol.mostrarInOrder();
     /*ArbolRN<int> arbol2;
     for (int i = 1; i <= 10000; i++)
     {
         arbol2.Insertar(i);
     }
     arbol2.mostrarPreOrder();*/
    ArbolRN<int> arbol3;
    leerDeArchivo(arbol3);
    // cout<<arbol.revisarRojoNegro()<<endl;
    if (arbol.revisarRojoNegro() == 1)
    {
        cout << "respuesta es verdadera ,el arbol tiene nodos rojos con hijos negros" << endl;
    }
    else
    {
        cout << "la respuesta es falsa, el arbol no esta nivelado con nodos rojos e hilos negros" << endl;
    }
    // arbol3.mostrarPostOrder();
    cout << "contando total" << endl;
    cout << arbol3.Contar() << endl;
    cout << "altura total" << endl;
    cout << arbol3.Altura() << endl;
    cout << "altura negra" << endl;
    cout << arbol3.AlturaNegra() << endl;

}
