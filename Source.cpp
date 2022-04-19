#include "AVL.h"

#include <set>
#include <fstream>
#include <iterator>

void leerDeArchivo(ArbolVL<int>& arbolBinario)
{
    ifstream archi;
    int numerosArchivo;
    archi.open("10000_Numeros.txt");

    if (!archi)
        cout << "No se puede abrir";
    else
        while (!archi.eof() && archi >> numerosArchivo)
        {
            arbolBinario.insertar(numerosArchivo);
        }
    archi.close();
}

void leerDeArchivoSET(set<int>& s1)
{
    ifstream archi;
    int numerosArchivo;
    archi.open("10000_Numeros.txt");

    if (!archi)
        cout << "No se puede abrir";
    else
        while (!archi.eof() && archi >> numerosArchivo)
        {
            s1.insert(numerosArchivo);
        }
    archi.close();
}

int main()
{
    set<int> s1;
    ArbolVL<int> arbol1;

    leerDeArchivo(arbol1);

//    leerDeArchivoSET(s1);

  /*  bool encontrado;
    for (int i = 0; i < 10000000; i++)
    {
        encontrado = arbol1.Buscar2(rand() % 10000);
    }

    for (int j = 0; j < 10000000; j++)
    {
        s1.find(rand() % 10000);
    }
    */
    arbol1.mostrarInOrder();
    return 0;
}