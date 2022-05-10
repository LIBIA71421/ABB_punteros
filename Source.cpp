#include "ArbolTRIE.h"
#include <fstream>
#include <string.h>

int main()
{
    ArbolTRIE<string>* arbol = new ArbolTRIE<string>();

    arbol.Insertar('a');
    arbol.Insertar('l');
    arbol.Insertar('g');
    arbol.Insertar('e');
    arbol.Insertar('b');
    arbol.Insertar('r');
    arbol.Insertar('a');
    arbol.Insertar('n');
    arbol.Insertar('a');            
    arbol3.mostrarInOrder();

}