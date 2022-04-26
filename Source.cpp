#include "MB.h"
#include <fstream>
#include <string.h>
#include <map>

void leerDeArchivo(MB<int>& arbol) {
    ifstream archi;
    int numerosArchivo;
    archi.open("10000_Numeros.txt");

    if (!archi)
        cout << "No se puede abrir";
    else
        while (!archi.eof() && archi >> numerosArchivo)
        {
            arbol.insertar(numerosArchivo);
        }
    archi.close();
}
void showlist(list <int> lista)
{
    list <int> ::iterator i;
    for (i = lista.begin(); i != lista.end(); ++i)
    {
        //cout << '\t' << *i;
        cout << *i << endl;
    }
    cout << endl;
}

void heap_Sort(MB<int>& arbol, list <int> lista)
{
    for (int i = 0; i < 10000; i++)
    {
        lista.push_back(arbol.eliminar());
    }
    showlist(lista);
}

int main()
{
    MB<int> arbol;
    int elem;
    int op;
    do {
        cout << " \n\n1. Insertar Elementos  ";
        cout << " \n2. Insertar Archivo Enteros";
        cout << " \n3. Mostrar Recorrer lista  ";
        cout << " \n4. Eliminar Mayor  ";
        cout << " \n5. Mayor  ";
        cout << " \n6. Menor ";
        cout << " \n7. Tam ";
        cout << " \n8. HEAP-SORT >>  ";
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> elem;
            arbol.insertar(elem);
            break;
        case 2:
            leerDeArchivo(arbol);
            arbol.recorrer();
            break;
        case 3:
            arbol.recorrer();
            break;
        case 4:
            arbol.eliminar();
            arbol.recorrer();
            break;
        case 5:
            cout << "El mayor es: " << arbol.getMayor() << endl;
            break;
        case 6:            
            cout << "El menor es: " << arbol.getMenor() << endl;
            break;
        case 7:
            cout << "La altura es: " << arbol.getTam() << endl;
            break;
        case 8:
            arbol.Heap_Sort();
            break;
        case 9:
            MB<int> mb;
            leerDeArchivo(mb);
            list <int> lista;
            heap_Sort(mb, lista);
            break;
        }
    } while (op != 0);
    
    return 0;
}