#include "ArbolRN.h"
#include <fstream>
#include <string.h>

void leerDeArchivo(ArbolRN<int>& arbolBinario)
{
    fstream ar;
    int numerosArchivo;

    ar.open("10000_Numeros.txt", ios::in);
    if (!ar)
        cout << "No se puede abrir";
    else
        while (ar >> numerosArchivo)
        {
            arbolBinario.Insertar(numerosArchivo);
        }
    ar.close();
}
void leerDeArchivoT(ArbolRN<string>& arbolBinario)
{
    fstream ar;
    string numerosArchivo;

    ar.open("cien.txt", ios::in);
    if (!ar)
        cout << "No se puede abrir";
    else
        while (ar >> numerosArchivo)
        {
            arbolBinario.Insertar(numerosArchivo);
        }
    ar.close();
}

int main()
{
    ArbolRN<string> arbolC;
    ArbolRN<int> arbol;
    ArbolRN<int> arbol3;

    int op;
    do {
        cout << " \n1. Insertar Elementos \n ";
        cout << " \n2. Insertar Archivo\n ";
        cout << " \n3. Mostrar InOrder \n ";
        cout << " \n4. Contar Nodos \n ";
        cout << " \n5. Contar Altura \n ";
        cout << " \n6. Revisar ";
        cout << " \n7. ARCHIVO CIEN ";
        cin >> op;
        switch (op)
        {
            case 1:
                arbol.Insertar(7);
                arbol.Insertar(15);
                arbol.Insertar(8);
                arbol.Insertar(12);
                arbol.Insertar(9);
                arbol.Insertar(5);
                arbol.Insertar(3);
                arbol.Insertar(2);
                break;
            case 2:
                leerDeArchivo(arbol3);
                break;
            case 3:
                arbol3.mostrarInOrder();
                break;
            case 4:
                cout << "contando total" << endl;
                cout << arbol3.Contar() << endl;
                break;
            case 5:
                cout << "altura total" << endl;
                cout << arbol3.Altura() << endl;
                break;
            case 6:
                if (arbol.revisarRojoNegro() == 1)
                {
                    cout << "respuesta es verdadera ,el arbol tiene nodos rojos con hijos negros" << endl;
                }
                else
                {
                    cout << "la respuesta es falsa, el arbol no esta nivelado con nodos rojos e hilos negros" << endl;
                }
                break;
            case 7:
                leerDeArchivoT(arbolC);
                arbolC.mostrarInOrder();
                break;
        }
    } while (op != 0);

}